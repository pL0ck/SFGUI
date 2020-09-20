#include <SFGUI/Property.hpp>

namespace sfg
{
	Property::Property()
	{
		//Add stuff
	}

	//const std::string* Property::GetValue(const std::string& property, std::shared_ptr<const Widget> widget) const
	//{
	//	// Look for property.
	//	PropertyMap::const_iterator prop_iter(Properties.find(property));

	//	const std::string* value = 0;
	//	int score = -1;

	//	if (prop_iter != Properties.end())
	//	{
	//		WidgetNameMap::const_iterator name_iter;

	//		if (widget)
	//		{
	//			// Find widget-specific properties, first.
	//			name_iter = prop_iter->second.find(widget->GetName());

	//			if (name_iter != prop_iter->second.end())
	//			{
	//				// Check against selectors.
	//				for (const auto& selector_value : name_iter->second)
	//				{
	//					if (selector_value.first->Matches(widget))
	//					{
	//						// Found, check if it is better than current best.
	//						auto new_score = selector_value.first->GetScore();

	//						if (new_score > score)
	//						{
	//							value = &selector_value.second;
	//							score = new_score;
	//						}
	//					}
	//				}
	//			}
	//		}

	//		// Look for general properties now.
	//		name_iter = prop_iter->second.find("*");

	//		if (name_iter != prop_iter->second.end())
	//		{
	//			for (const auto& selector_value : name_iter->second)
	//			{
	//				if (selector_value.first->Matches(widget))
	//				{
	//					// Found, check if it is better than current best.
	//					auto new_score = selector_value.first->GetScore();

	//					if (new_score > score)
	//					{
	//						value = &selector_value.second;
	//						score = new_score;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	return value;
	//}

	//bool Property::SetProperty(std::shared_ptr<Selector> selector, const std::string& property, const std::string& value)
	//{
	//	if (!selector)
	//		// Invalid selector string given.
	//		return false;

	//	// If the selector does already exist, we'll remove it to make sure the newly
	//	// added value will get a higher priority than the previous one, because
	//	// that's the expected behaviour (LIFO).
	//	SelectorValueList& list(Properties[property][selector->GetWidgetName()]); // Shortcut.
	//	SelectorValueList::iterator list_begin(list.begin());
	//	SelectorValueList::iterator list_end(list.end());

	//	for (; list_begin != list_end; ++list_begin)
	//	{
	//		if (*list_begin->first == *selector)
	//		{
	//			// Equal, remove.
	//			list.erase(list_begin);
	//			break;
	//		}
	//	}

	//	// Insert at top to get highest priority.
	//	list.insert(list.begin(), SelectorValuePair(selector, value));

	//	if (m_auto_refresh)
	//		Widget::RefreshAll();

	//	return true;
	//}

}


