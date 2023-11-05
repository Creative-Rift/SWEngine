/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Color.hpp
*/

#ifndef SHIPWRECK_ENGINE_COLOR_HPP
#define SHIPWRECK_ENGINE_COLOR_HPP

#include "SWEngine.hpp"

namespace sw {

    class SW_MODULE_EXPORT Color {
        public:
            float r; /// Red value
            float g; /// Green value
            float b; /// Blue value
            float a; /// Alpha value

            /// @brief Default constructor
            ///
            /// Build default black color (0, 0, 0, 255)
            constexpr Color();

            /// @brief Construct custom color
            ///
            /// @param red      Value in range [0, 255]
            /// @param green    Value in range [0, 255]
            /// @param blue     Value in range [0, 255]
            /// @param alpha    Value in range [0, 255]
            constexpr Color(float red, float green, float blue, float alpha = 255);
    }; // class Color

    #include "Color.inl"

    extern SW_MODULE_EXPORT Color BlackColor;         /// Black color
    extern SW_MODULE_EXPORT Color WhiteColor;         /// White color
    extern SW_MODULE_EXPORT Color RedColor;           /// Red color
    extern SW_MODULE_EXPORT Color GreenColor;         /// Green color
    extern SW_MODULE_EXPORT Color BlueColor;          /// Blue color
    extern SW_MODULE_EXPORT Color YellowColor;        /// Yellow color
    extern SW_MODULE_EXPORT Color MagentaColor;       /// Magenta color
    extern SW_MODULE_EXPORT Color CyanColor;          /// Cyan color
    extern SW_MODULE_EXPORT Color TransparentColor;   /// Transparent (black) color

} // sw

#endif //SHIPWRECK_ENGINE_COLOR_HPP
