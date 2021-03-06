#include <SFGUI/LayoutPanel.hpp>
#include <SFGUI/Context.hpp>
#include <SFGUI/Engine.hpp>

#include <iterator>

namespace sfg {

	LayoutPanel::LayoutPanel( Orientation orientation, float spacing ) :
	m_spacing( spacing ),
	m_orientation( orientation )
{
}

LayoutPanel::Ptr LayoutPanel::Create( Orientation orientation, float spacing ) {
	return Ptr( new LayoutPanel( orientation, spacing ) );
}

const std::string& LayoutPanel::GetName() const {
	static const std::string name( "LayoutPanel" );
	return name;
}

void LayoutPanel::AddEnd( Widget::Ptr widget, bool expand, bool fill ) {
	if( IsChild( widget ) ) {
		return;
	}

	// It's important to create the ChildInfo object first, so that the
	// HandleAdd() method recognized the widget as a correctly packed one.
	m_LayoutPanel_children.push_back( ChildInfo( widget, expand, fill ) );
	Add( widget );
}

void LayoutPanel::AddStart( Widget::Ptr widget, bool expand, bool fill ) {
	if( IsChild( widget ) ) {
		return;
	}

	// It's important to create the ChildInfo object first, so that the
	// HandleAdd() method recognized the widget as a correctly packed one.
	m_LayoutPanel_children.push_front( ChildInfo( widget, expand, fill ) );
	Add( widget );
}

void LayoutPanel::AddControl( Widget::Ptr widget, bool expand, bool fill ) {
	AddEnd( widget, expand, fill );
}

void LayoutPanel::ReorderChild( Widget::Ptr widget, std::size_t position ) {
	ChildrenCont::iterator iter( std::find( m_LayoutPanel_children.begin(), m_LayoutPanel_children.end(), widget ) );

	if( iter == m_LayoutPanel_children.end() ) {
		return;
	}

	position = std::min( position, m_LayoutPanel_children.size() - 1 );

	ChildrenCont::iterator insertion_point( m_LayoutPanel_children.begin() );
	std::advance( insertion_point, static_cast<ChildrenCont::difference_type>( position ) );
	m_LayoutPanel_children.insert( insertion_point, *iter );
	m_LayoutPanel_children.erase( iter );

	Invalidate();
	AllocateChildren();
}

bool LayoutPanel::HandleAdd( Widget::Ptr child ) {
	ChildrenCont::const_iterator iter( std::find( m_LayoutPanel_children.begin(), m_LayoutPanel_children.end(), child ) );

	// If there's no ChildInfo present for the widget, the user added the widget
	// manually, which is not allowed for this class.
	if( iter == m_LayoutPanel_children.end() ) {

#if defined( SFGUI_DEBUG )
		std::cerr << "SFGUI warning: Child must be added via Pack() for sfg::LayoutPanel widgets.\n";
#endif

		return false;
	}

	Container::HandleAdd( child );

	RequestResize();
	Invalidate();

	return true;
}

void LayoutPanel::HandleRemove( Widget::Ptr child ) {
	ChildrenCont::iterator iter( std::find( m_LayoutPanel_children.begin(), m_LayoutPanel_children.end(), child ) );

	if( iter != m_LayoutPanel_children.end() ) {
		m_LayoutPanel_children.erase( iter );
	}

	RequestResize();
	Invalidate();
}

sf::Vector2f LayoutPanel::CalculateRequisition() {
	sf::Vector2f requisition( 0.f, 0.f );
	unsigned int num_visible( 0 );

	for( const auto& child : m_LayoutPanel_children ) {
		if( !IsChildInteresting( child.widget ) ) {
			continue;
		}

		++num_visible;

		sf::Vector2f child_requisition( child.widget->GetRequisition() );

		if( m_orientation == Orientation::HORIZONTAL ) {
			requisition.x += child_requisition.x;
			requisition.y = std::max( requisition.y, child_requisition.y );
		}
		else {
			requisition.x = std::max( requisition.x, child_requisition.x );
			requisition.y += child_requisition.y;
		}
	}

	if( num_visible > 1 ) {
		if( m_orientation == Orientation::HORIZONTAL ) {
			requisition.x += static_cast<float>( num_visible - 1 ) * GetSpacing();
		}
		else {
			requisition.y += static_cast<float>( num_visible - 1 ) * GetSpacing();
		}
	}

	float gap( Context::Get().GetEngine().GetProperty<float>( "Gap", shared_from_this() ) );
	requisition.x += 2 * gap;
	requisition.y += 2 * gap;

	return requisition;
}

void LayoutPanel::HandleSizeChange() {
	AllocateChildren();
}

LayoutPanel::ChildInfo::ChildInfo( Widget::Ptr widget_, bool expand_, bool fill_ ) :
	widget( widget_.get() ),
	expand( expand_ ),
	fill( fill_ )
{
}

bool LayoutPanel::ChildInfo::operator==( const ChildInfo& rhs ) const {
	return widget == rhs.widget;
}

void LayoutPanel::SetSpacing( float spacing ) {
	m_spacing = spacing;
	RequestResize();
	Invalidate();
}

void LayoutPanel::SetOrientation( Orientation orientation ) {
	m_orientation = orientation;
	RequestResize();
	Invalidate();
}

float LayoutPanel::GetSpacing() const {
	return m_spacing;
}

LayoutPanel::Orientation LayoutPanel::GetOrientation() const {
	return m_orientation;
}

void LayoutPanel::AllocateChildren() const {
	unsigned int num_expand( 0 );
	unsigned int num_visible( 0 );

	// Count number of visible and expanded children.
	for( const auto& child : m_LayoutPanel_children ) {
		if( !IsChildInteresting( child.widget ) ) {
			continue;
		}

		++num_visible;

		if( child.expand ) {
			++num_expand;
		}
	}

	// Calculate extra width pre expanded widget.
	float extra( 0.f );

	if( num_expand > 0 ) {
		if( m_orientation == Orientation::HORIZONTAL ) {
			extra = std::max( 0.f, GetAllocation().width - GetRequisition().x ) / static_cast<float>( num_expand );
		}
		else {
			extra = std::max( 0.f, GetAllocation().height - GetRequisition().y ) / static_cast<float>( num_expand );
		}
	}

	// Allocate children.
	float gap( Context::Get().GetEngine().GetProperty<float>( "Gap", shared_from_this() ) );
	sf::Vector2f allocation( 0.f, 0.f );
	sf::Vector2f position( gap, gap );

	for( const auto& child : m_LayoutPanel_children ) {
		if( !IsChildInteresting( child.widget ) ) {
			continue;
		}

		if( m_orientation == Orientation::HORIZONTAL ) {
			allocation.x = child.widget->GetRequisition().x + ( child.expand ? extra : 0.f );
			allocation.y = GetAllocation().height - 2 * gap;

			child.widget->SetAllocation( sf::FloatRect( position.x, position.y, allocation.x - ( child.expand && !child.fill ? extra : 0.f ), allocation.y ) );
			position.x += allocation.x + GetSpacing();
		}
		else {
			allocation.x = GetAllocation().width - 2 * gap;
			allocation.y = child.widget->GetRequisition().y + ( child.expand ? extra : 0.f );

			child.widget->SetAllocation( sf::FloatRect( position.x, position.y, allocation.x, allocation.y - ( child.expand && !child.fill ? extra : 0.f ) ) );
			position.y += allocation.y + GetSpacing();
		}

		--num_visible;
	}
}

bool LayoutPanel::IsChildInteresting( Widget* child ) const {
	return
		child->IsLocallyVisible() &&
		(child->GetRequisition().x > 0.f || child->GetAllocation().width > 0.0f) &&
		(child->GetRequisition().y > 0.f || child->GetAllocation().height > 0.0f)
	;
}

void LayoutPanel::HandleRequisitionChange() {
	AllocateChildren();
}

}
