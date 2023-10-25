/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Vector3.inl
** Description: [CHANGE]
*/

template <typename T>
requires std::is_arithmetic_v<T>
sw::Vector3<T>::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

template <typename T>
requires std::is_arithmetic_v<T>
sw::Vector3<T>::Vector3(T X, T Y, T Z)
{
    x = X;
    y = Y;
    z = Z;
}

template <typename T>
requires std::is_arithmetic_v<T>
sw::Vector3<T>::~Vector3()
= default;

template <typename T>
sw::Vector3<T> operator-(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z));
}

template <typename T>
sw::Vector3<T> operator-(const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(-right.x, -right.y, -right.z));
}

template <typename T>
sw::Vector3<T> operator+(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z));
}

template <typename T>
sw::Vector3<T> operator*(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x * right.x, left.y * right.y, left.z * right.z));
}

template <typename T>
sw::Vector3<T> operator*(const sw::Vector3<T>& left, T right)
{
    return (sw::Vector3<T>(left.x * right, left.y * right, left.z * right));
}

template <typename T>
sw::Vector3<T> operator/(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x / right.x, left.y / right.y, left.z / right.z));
}

template <typename T>
inline sw::Vector3<T> operator/(const sw::Vector3<T>& left, T right)
{
    return (sw::Vector3<T>(left.x / right, left.y / right, left.z / right));
}

template <typename T>
inline sw::Vector3<T>& operator-=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator+=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator*=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator*=(sw::Vector3<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator/=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator/=(sw::Vector3<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return (left);
}

template <typename T>
inline bool operator==(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return ((left.x == right.x) && (left.y == right.y));
}

template <typename T>
inline bool operator!=(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return ((left.x != right.x) || (left.y != right.y) || (left.z != right.z));
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const sw::Vector3<T>& matrix)
{
    os << "(" << matrix.x << ", " << matrix.y << ", " << matrix.z << ")";
    return (os);
}
