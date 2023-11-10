/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Rect.hpp
*/

#ifndef SHIPWRECK_ENGINE_RECT_HPP
#define SHIPWRECK_ENGINE_RECT_HPP

#include "SWEngine.hpp"

namespace sw {
    template<typename T>
    class SW_MODULE_EXPORT Rect {
        public:
            T left;
            T top;
            T width;
            T height;

            /// @brief Default Constructor of a Rect.
            ///
            /// Creates an empty Rect (it is equivalent to calling
            /// Rect(0, 0, 0, 0)).
            Rect();

            /// @brief Construct the Rect from given coordinates.
            ///
            /// @param rectLeft   Left coordinate
            /// @param rectTop    Top coordinate
            /// @param rectWidth  Width
            /// @param rectHeight Height
            Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight);

            /// @brief Construct the Rect from position and size
            ///
            /// @param position Position of the top-left corner
            /// @param size     Size of the Rect
            Rect(const sw::Vector2<T> &position, const sw::Vector2<T> &size);

            /// @brief Check if a point is inside the Rect's area
            ///
            /// @param x X coordinate of the point
            /// @param y Y coordinate of the point
            /// @return True if the point is inside, false otherwise.
            bool contains(T x, T y) const;

            /// @brief Check if a point is inside the Rect's area.
            ///
            /// @param point Point to test.
            /// @return True if the point is inside, false otherwise.
            bool contains(const sw::Vector2<T> &point) const;

            /// @brief Check the intersection between two Rects.
            ///
            /// @param rectangle Rect to test.
            /// @return True if the Rects overlap, false otherwise.
            bool intersects(const sw::Rect<T> &rectangle) const;

    }; // class Rect

    // Define mathematical operator
    template<typename T>
    Rect<T> operator+(const Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> operator-(const Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> operator*(const Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> operator/(const Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> operator%(const Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> &operator+=(Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> &operator-=(Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> &operator*=(Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> &operator/=(Rect<T> &left, const Rect<T> right);

    template<typename T>
    Rect<T> &operator%=(Rect<T> &left, const Rect<T> right);

    /// Define conditional operator
    template<typename T>
    bool operator==(const Rect<T> &left, const Rect<T> &right);

    template<typename T>
    bool operator!=(const Rect<T> &left, const Rect<T> &right);

    template<typename T>
    bool operator<(const Rect<T> &left, const Rect<T> &right);

    template<typename T>
    bool operator>(const Rect<T> &left, const Rect<T> &right);

    template<typename T>
    bool operator<=(const Rect<T> &left, const Rect<T> &right);

    template<typename T>
    bool operator>=(const Rect<T> &left, const Rect<T> &right);

    /// Define common types
    typedef Rect<int> IntRect;
    typedef Rect<float> FloatRect;
    typedef Rect<double> DoubleRect;

#include "Rect.inl"

} // SW

#endif //SHIPWRECK_ENGINE_RECT_HPP
