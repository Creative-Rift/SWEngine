/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Vector2.hpp
*/

#ifndef SHIPWRECK_ENGINE_VECTOR2_HPP
#define SHIPWRECK_ENGINE_VECTOR2_HPP

#include <ostream>

namespace sw {
    template<typename T>
    class Vector2 {

        public:
            /// @brief X Coordinate
            T x;

            /// @brief Y Coordinate
            T y;

            /// @brief Default constructor.
            ///
            /// Creates a Vector2(0, 0).
            Vector2();

            /// @brief Construct the vector from the given coordinates.
            ///
            /// @param X X coordinate.
            /// @param Y Y coordinate.
            Vector2(T x, T y);

            /// @brief Default destructor.
            ~Vector2() = default;

    }; // class Vector2

    /// @relates Vector2
    /// @brief Overload operator -
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise subtraction of both vectors
    template<typename T>
    Vector2<T> operator-(const sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload of unary operator -
    ///
    /// @param right Vector to negate
    ///
    /// @return Memberwise opposite of the vector
    template<typename T>
    Vector2<T> operator-(const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator +
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise addition of both vectors
    template<typename T>
    Vector2<T> operator+(const sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator *
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise multiplication of both vectors
    template<typename T>
    Vector2<T> operator*(const sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator *
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise multiplication by right
    template<typename T>
    Vector2<T> operator*(const sw::Vector2<T> &left, T right);

    /// @relates Vector2
    /// @brief Overload operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise division of both vectors
    template<typename T>
    Vector2<T> operator/(const sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise division by right
    template<typename T>
    Vector2<T> operator/(const sw::Vector2<T> &left, T right);

    /// @relates Vector2
    /// @brief Overload operator -=
    ///
    /// This operator performs a memberwise subtraction of both vectors,
    /// and assigns the result to left.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Reference to left
    template<typename T>
    Vector2<T> &operator-=(sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator +=
    ///
    /// This operator performs a memberwise addition of both vectors,
    /// and assigns the result to left.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Reference to left
    template<typename T>
    Vector2<T> &operator+=(sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator *=
    ///
    /// This operator performs a memberwise multiplication of both vectors,
    /// and assigns the result to left.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Reference to left
    template<typename T>
    Vector2<T> &operator*=(sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @return Reference to left
    //
    template<typename T>
    Vector2<T> &operator*=(sw::Vector2<T> &left, T right);

    /// @relates Vector2
    /// @brief Overload operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise division of both vectors
    template<typename T>
    Vector2<T> &operator/=(sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise division by right
    template<typename T>
    Vector2<T> &operator/=(sw::Vector2<T> &left, T right);

    /// @relates Vector2
    /// @brief Overload operator ==
    ///
    /// This operator compares strict equality between two vectors.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return True if left is equal to right
    template<typename T>
    bool operator==(const sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// @relates Vector2
    /// @brief Overload operator !=
    ///
    /// This operator compares strict difference between two vectors.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return True if left is not equal to right
    template<typename T>
    bool operator!=(const sw::Vector2<T> &left, const sw::Vector2<T> &right);

    /// Define the most common types
    typedef Vector2<int> Vector2i;
    typedef Vector2<unsigned int> Vector2u;
    typedef Vector2<float> Vector2f;

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Vector2<T> &vector);

#include "Vector2.inl"

} // sw

#endif // SHIPWRECK_ENGINE_VECTOR2_HPP