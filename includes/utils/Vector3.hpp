/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Vector3.hpp
*/
#ifndef SHIPWRECK_ENGINE_VECTOR3_HPP
#define SHIPWRECK_ENGINE_VECTOR3_HPP

#include <ostream>
#include "SWEngine.hpp"

namespace sw {

    template<typename T> requires std::is_arithmetic_v<T>
    class SW_MODULE_EXPORT Vector3 {
        public:
            /// Coordinate X, Y, Z.
            T x;
            T y;
            T z;

            /// \brief Default constructor.
            ///
            /// Creates a Vector3(0, 0).
            Vector3();

            /// \brief Construct the vector from the given coordinates.
            ///
            /// \param X X coordinate.
            /// \param Y Y coordinate.
            /// \param Z Z coordinate.
            Vector3(T x, T y, T z);

            /// \brief Default destructor.
            ~Vector3();

    }; // class Vector3

    /// \brief Overload of binary operator -
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return Subtraction of both vectors
    template<typename T>
    Vector3<T> operator-(const sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of unary operator -
    ///
    /// \param right sw::Vector3
    /// \return Opposite of the vector
    template<typename T>
    Vector3<T> operator-(const sw::Vector3<T> &right);

    /// \brief Overload of binary operator +
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return Addition of both vectors
    template<typename T>
    Vector3<T> operator+(const sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of binary operator *
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return Multiplication of both vectors
    template<typename T>
    Vector3<T> operator*(const sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of binary operator *
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (a scalar value)
    /// \return Multiplication by right
    template<typename T>
    Vector3<T> operator*(const sw::Vector3<T> &left, T right);

    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return Division of both vectors
    template<typename T>
    Vector3<T> operator/(const sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (a scalar value)
    /// \return Division by right
    template<typename T>
    Vector3<T> operator/(const sw::Vector3<T> &left, T right);

    /// \brief Overload of binary operator -=
    /// This operator performs a subtraction of both vectors,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return Reference to left
    template<typename T>
    Vector3<T> &operator-=(sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of binary operator +=
    /// This operator performs a addition of both vectors,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    ///
    /// \return Reference to left
    template<typename T>
    Vector3<T> &operator+=(sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of binary operator *=
    /// This operator performs a multiplication of both vectors,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return Reference to left
    template<typename T>
    Vector3<T> &operator*=(sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of binary operator *=
    /// This operator performs a multiplication with a scalar value,
    /// and assigns the result to left.
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (scalar value)
    /// \return Reference to left
    template<typename T>
    Vector3<T> &operator*=(sw::Vector3<T> &left, T right);

    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (a scalar value)
    /// \return Reference to left
    template<typename T>
    Vector3<T> &operator/=(sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \relates Vector2
    /// \brief Overload of binary operator /
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (a scalar value)
    /// \return Reference to left
    template<typename T>
    Vector3<T> &operator/=(sw::Vector3<T> &left, T right);

    /// \brief Overload of binary operator ==
    /// This operator compares strict equality between two vectors.
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return boolean
    template<typename T>
    bool operator==(const sw::Vector3<T> &left, const sw::Vector3<T> &right);

    /// \brief Overload of binary operator !=
    /// This operator compares strict difference between two vectors.
    ///
    /// \param left  Left operand (Vector3)
    /// \param right Right operand (Vector3)
    /// \return boolean
    template<typename T>
    bool operator!=(const sw::Vector3<T> &left, const sw::Vector3<T> &right);


    /// Define the most common types
    typedef Vector3<int> Vector3i;
    typedef Vector3<unsigned int> Vector3u;
    typedef Vector3<float> Vector3f;
    typedef Vector3<double> Vector3d;

#include "Vector3.inl"

} // sw

#endif //SHIPWRECK_ENGINE_VECTOR3_HPP
