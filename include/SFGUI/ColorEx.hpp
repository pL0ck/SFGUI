#pragma once
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>

#include <SFGUI/Config.hpp>

#include <algorithm>
#include <cstdlib>

namespace sfg {
    namespace ColorEx {

        const sf::Color AliceBlue(0xF0F8FFFF);
        const sf::Color AntiqueWhite(0xFAEBD7FF);
        const sf::Color Aqua(0x00FFFFFF);
        const sf::Color Aquamarine(0x7FFFD4FF);
        const sf::Color Azure(0xF0FFFFFF);
        const sf::Color Beige(0xF5F5DCFF);
        const sf::Color Bisque(0xFFE4C4FF);
        const sf::Color Black(0x000000FF);
        const sf::Color BlanchedAlmond(0xFFEBCDFF);
        const sf::Color Blue(0x0000FFFF);
        const sf::Color BlueViolet(0x8A2BE2FF);
        const sf::Color Brown(0xA52A2AFF);
        const sf::Color BurlyWood(0xDEB887FF);
        const sf::Color CadetBlue(0x5F9EA0FF);
        const sf::Color Chartreuse(0x7FFF00FF);
        const sf::Color Chocolate(0xD2691EFF);
        const sf::Color Coral(0xFF7F50FF);
        const sf::Color CornflowerBlue(0x6495EDFF);
        const sf::Color Cornsilk(0xFFF8DCFF);
        const sf::Color Crimson(0xDC143CFF);
        const sf::Color Cyan(0x00FFFFFF);
        const sf::Color DarkBlue(0x00008BFF);
        const sf::Color DarkCyan(0x008B8BFF);
        const sf::Color DarkGoldenRod(0xB8860BFF);
        const sf::Color DarkGray(0xA9A9A9FF);
        const sf::Color DarkGrey(0xA9A9A9FF);
        const sf::Color DarkGreen(0x006400FF);
        const sf::Color DarkKhaki(0xBDB76BFF);
        const sf::Color DarkMagenta(0x8B008BFF);
        const sf::Color DarkOliveGreen(0x556B2FFF);
        const sf::Color DarkOrange(0xFF8C00FF);
        const sf::Color DarkOrchid(0x9932CCFF);
        const sf::Color DarkRed(0x8B0000FF);
        const sf::Color DarkSalmon(0xE9967AFF);
        const sf::Color DarkSeaGreen(0x8FBC8FFF);
        const sf::Color DarkSlateBlue(0x483D8BFF);
        const sf::Color DarkSlateGray(0x2F4F4FFF);
        const sf::Color DarkSlateGrey(0x2F4F4FFF);
        const sf::Color DarkTurquoise(0x00CED1FF);
        const sf::Color DarkViolet(0x9400D3FF);
        const sf::Color DeepPink(0xFF1493FF);
        const sf::Color DeepSkyBlue(0x00BFFFFF);
        const sf::Color DimGray(0x696969FF);
        const sf::Color DimGrey(0x696969FF);
        const sf::Color DodgerBlue(0x1E90FFFF);
        const sf::Color FireBrick(0xB22222FF);
        const sf::Color FloralWhite(0xFFFAF0FF);
        const sf::Color ForestGreen(0x228B22FF);
        const sf::Color Fuchsia(0xFF00FFFF);
        const sf::Color Gainsboro(0xDCDCDCFF);
        const sf::Color GhostWhite(0xF8F8FFFF);
        const sf::Color Gold(0xFFD700FF);
        const sf::Color GoldenRod(0xDAA520FF);
        const sf::Color Gray(0x808080FF);
        const sf::Color Grey(0x808080FF);
        const sf::Color Green(0x008000FF);
        const sf::Color GreenYellow(0xADFF2FFF);
        const sf::Color HoneyDew(0xF0FFF0FF);
        const sf::Color HotPink(0xFF69B4FF);
        const sf::Color IndianRed(0xCD5C5CFF);
        const sf::Color Indigo(0x4B0082FF);
        const sf::Color Ivory(0xFFFFF0FF);
        const sf::Color Khaki(0xF0E68CFF);
        const sf::Color Lavender(0xE6E6FAFF);
        const sf::Color LavenderBlush(0xFFF0F5FF);
        const sf::Color LawnGreen(0x7CFC00FF);
        const sf::Color LemonChiffon(0xFFFACDFF);
        const sf::Color LightBlue(0xADD8E6FF);
        const sf::Color LightCoral(0xF08080FF);
        const sf::Color LightCyan(0xE0FFFFFF);
        const sf::Color LightGoldenRodYellow(0xFAFAD2FF);
        const sf::Color LightGray(0xD3D3D3FF);
        const sf::Color LightGrey(0xD3D3D3FF);
        const sf::Color LightGreen(0x90EE90FF);
        const sf::Color LightPink(0xFFB6C1FF);
        const sf::Color LightSalmon(0xFFA07AFF);
        const sf::Color LightSeaGreen(0x20B2AAFF);
        const sf::Color LightSkyBlue(0x87CEFAFF);
        const sf::Color LightSlateGray(0x778899FF);
        const sf::Color LightSlateGrey(0x778899FF);
        const sf::Color LightSteelBlue(0xB0C4DEFF);
        const sf::Color LightYellow(0xFFFFE0FF);
        const sf::Color Lime(0x00FF00FF);
        const sf::Color LimeGreen(0x32CD32FF);
        const sf::Color Linen(0xFAF0E6FF);
        const sf::Color Magenta(0xFF00FFFF);
        const sf::Color Maroon(0x800000FF);
        const sf::Color MediumAquaMarine(0x66CDAAFF);
        const sf::Color MediumBlue(0x0000CDFF);
        const sf::Color MediumOrchid(0xBA55D3FF);
        const sf::Color MediumPurple(0x9370DBFF);
        const sf::Color MediumSeaGreen(0x3CB371FF);
        const sf::Color MediumSlateBlue(0x7B68EEFF);
        const sf::Color MediumSpringGreen(0x00FA9AFF);
        const sf::Color MediumTurquoise(0x48D1CCFF);
        const sf::Color MediumVioletRed(0xC71585FF);
        const sf::Color MidnightBlue(0x191970FF);
        const sf::Color MintCream(0xF5FFFAFF);
        const sf::Color MistyRose(0xFFE4E1FF);
        const sf::Color Moccasin(0xFFE4B5FF);
        const sf::Color NavajoWhite(0xFFDEADFF);
        const sf::Color Navy(0x000080FF);
        const sf::Color OldLace(0xFDF5E6FF);
        const sf::Color Olive(0x808000FF);
        const sf::Color OliveDrab(0x6B8E23FF);
        const sf::Color Orange(0xFFA500FF);
        const sf::Color OrangeRed(0xFF4500FF);
        const sf::Color Orchid(0xDA70D6FF);
        const sf::Color PaleGoldenRod(0xEEE8AAFF);
        const sf::Color PaleGreen(0x98FB98FF);
        const sf::Color PaleTurquoise(0xAFEEEEFF);
        const sf::Color PaleVioletRed(0xDB7093FF);
        const sf::Color PapayaWhip(0xFFEFD5FF);
        const sf::Color PeachPuff(0xFFDAB9FF);
        const sf::Color Peru(0xCD853FFF);
        const sf::Color Pink(0xFFC0CBFF);
        const sf::Color Plum(0xDDA0DDFF);
        const sf::Color PowderBlue(0xB0E0E6FF);
        const sf::Color Purple(0x800080FF);
        const sf::Color RebeccaPurple(0x663399FF);
        const sf::Color Red(0xFF0000FF);
        const sf::Color RosyBrown(0xBC8F8FFF);
        const sf::Color RoyalBlue(0x4169E1FF);
        const sf::Color SaddleBrown(0x8B4513FF);
        const sf::Color Salmon(0xFA8072FF);
        const sf::Color SandyBrown(0xF4A460FF);
        const sf::Color SeaGreen(0x2E8B57FF);
        const sf::Color SeaShell(0xFFF5EEFF);
        const sf::Color Sienna(0xA0522DFF);
        const sf::Color Silver(0xC0C0C0FF);
        const sf::Color SkyBlue(0x87CEEBFF);
        const sf::Color SlateBlue(0x6A5ACDFF);
        const sf::Color SlateGray(0x708090FF);
        const sf::Color SlateGrey(0x708090FF);
        const sf::Color Snow(0xFFFAFAFF);
        const sf::Color SpringGreen(0x00FF7FFF);
        const sf::Color SteelBlue(0x4682B4FF);
        const sf::Color Tan(0xD2B48CFF);
        const sf::Color Teal(0x008080FF);
        const sf::Color Thistle(0xD8BFD8FF);
        const sf::Color Tomato(0xFF6347FF);
        const sf::Color Turquoise(0x40E0D0FF);
        const sf::Color Violet(0xEE82EEFF);
        const sf::Color Wheat(0xF5DEB3FF);
        const sf::Color White(0xFFFFFFFF);
        const sf::Color WhiteSmoke(0xF5F5F5FF);
        const sf::Color Yellow(0xFFFF00FF);
        const sf::Color YellowGreen(0x9ACD32FF);
    }

}