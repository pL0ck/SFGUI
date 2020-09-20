#pragma once
#include <SFGUI/Config.hpp>
#include <SFGUI/Selector.hpp>
#include <SFGUI/Widget.hpp>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <memory>

namespace sfg
{
	//template <typename T>
	//T GetProperty(const std::string& property, std::shared_ptr<const Widget> widget) const {
	//	static const T default_ = T();

	//	const std::string* value(GetValue(property, widget));
	//	if (!value) {
	//		return default_;
	//	}

	//	// If string is requested, just return the value.
	//	if (typeid(T) == typeid(std::string)) {
	//		// reinterpret_cast is needed here to fool the compiler. Else it will try
	//		// to compile "return *value" for all Ts, which may fail for
	//		// GetProperty<int> here, because it would be tried to return a std::string
	//		// in this case which fails.
	//		return *reinterpret_cast<const T*>(value);
	//	}

	//	// Convert value.
	//	T out_value;
	//	std::istringstream sstr(*value);
	//	sstr >> out_value;

	//	if (sstr.fail()) {
	//		std::string error_message("GetProperty: Unable to convert string to requested type.");
	//		error_message += " Property: " + property;
	//		error_message += " Requested type: ";
	//		error_message += typeid(T).name();
	//		error_message += " Value: " + *value;
	//		throw BadValueException(error_message);
	//	}

	//	return out_value;
	//}

	//template <typename T>
	//bool SetProperty(const std::string& selector, const std::string& property, const T& value) {
	//	std::ostringstream properties;

	//	properties << selector << " {\n\t" << property << ": " << value << ";\n}";

	//	return SetProperties(properties.str());
	//}

	//template <typename T>
	//bool SetProperty(std::shared_ptr<Selector> selector, const std::string& property, const T& value) {
	//	std::ostringstream sstr;
	//	sstr << value;

	//	if (sstr.fail()) {
	//		return false;
	//	}

	//	return SetProperty(selector, property, sstr.str());
	//}

	class SFGUI_API Property
	{


	public:
		Property();
		~Property() = default;
	//	/** Set property.
	//	 * @param selector selector string (leave empty for all widgets).
	//	 * @param property Property.
	//	 * @param value Value.
	//	 * @return true on success, false when: Invalid selector or invalid property.
	//	 * @throws BadValue when value couldn't be converted to string.
	//	 */
	//	template <typename T>
	//	bool SetProperty(const std::string& selector, const std::string& property, const T& value);

	//	/** Set property.
	//	 * @param selector Valid selector object.
	//	 * @param property Property.
	//	 * @param value Value.
	//	 * @return true on success, false when: Invalid selector or invalid property.
	//	 * @throws BadValue when value couldn't be converted to string.
	//	 */
	//	template <typename T>
	//	bool SetProperty(std::shared_ptr<Selector> selector, const std::string& property, const T& value);

	//	/** Set property.
	//	 * @param selector Valid selector object.
	//	 * @param property Property.
	//	 * @param value Value.
	//	 * @return true on success, false when: Invalid selector or invalid property.
	//	 */
	//	bool SetProperty(std::shared_ptr<Selector> selector, const std::string& property, const std::string& value);

	//	typedef std::pair<std::shared_ptr<const Selector>, std::string> SelectorValuePair;
	//	typedef std::vector<SelectorValuePair> SelectorValueList;
	//	typedef std::map<const std::string, SelectorValueList> WidgetNameMap;
	//	typedef std::map<const std::string, WidgetNameMap> PropertyMap;
	//	PropertyMap Properties;

	//	//void ClearProperties();

	//	const bool AutoRefresh() const { return m_auto_refresh; }
	//	void AutoRefresh(const bool& auto_refresh) {m_auto_refresh=auto_refresh;}
	//	//const PropertyMap Properties() const { return m_properties; }
	//	//void Properties(const PropertyMap& property_map) { m_properties = property_map; }

	//private:
	//	const std::string* GetValue(const std::string& property, std::shared_ptr<const Widget> widget) const;
	//	bool m_auto_refresh;
	};
}