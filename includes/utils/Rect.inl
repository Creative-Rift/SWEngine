/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Rect.inl
*/

template<typename T>
inline Rect<T>::Rect() :
    left(0),
    top(0),
    width(0),
    height(0)
{}

template<typename T>
inline Rect<T>::Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight) :
    left(rectLeft),
    top(rectTop),
    width(rectWidth),
    height(rectHeight)
{}

template<typename T>
inline Rect<T>::Rect(const Vector2<T> &position, const Vector2<T> &size) :
    left(position.x),
    top(position.y),
    width(size.x),
    height(size.y)
{}

template<typename T>
inline bool Rect<T>::contains(T x, T y) const
{
    return x >= left && x <= left + width
        && y >= top && y <= top + height;
}

template<typename T>
inline bool Rect<T>::contains(const Vector2<T> &point) const
{
    return point.x >= left && point.x <= left + width
        && point.y >= top && point.y <= top + height;
}

template<typename T>
inline bool Rect<T>::intersects(const Rect<T> &rectangle) const
{
    return rectangle.left + rectangle.width <= left || rectangle.left >= left + width
        || rectangle.top + rectangle.height <= top || rectangle.top >= top + height;
}

template<typename T>
inline Rect<T> operator+(const Rect<T> &left, const Rect<T> right)
{
    return Rect<T>{left.left, left.top, left.width + right.width, left.height + right.height};
}

template<typename T>
inline Rect<T> operator-(const Rect<T> &left, const Rect<T> right)
{
    return Rect<T>{left.left, left.top, left.width - right.width, left.height - right.height};
}

template<typename T>
inline Rect<T> operator*(const Rect<T> &left, const Rect<T> right)
{
    return Rect<T>{left.left, left.top, left.width * right.width, left.height * right.height};
}

template<typename T>
inline Rect<T> operator/(const Rect<T> &left, const Rect<T> right)
{
    return Rect<T>{left.left, left.top, left.width / right.width, left.height / right.height};
}

template<typename T>
inline Rect<T> operator%(const Rect<T> &left, const Rect<T> right)
{
    return Rect<T>{left.left, left.top, left.width % right.width, left.height % right.height};
}

template<typename T>
inline Rect<T> &operator+=(Rect<T> &left, const Rect<T> right)
{
    left.width += right.width;
    left.height += right.height;
    return left;
}

template<typename T>
inline Rect<T> &operator-=(Rect<T> &left, const Rect<T> right)
{
    left.width -= right.width;
    left.height -= right.height;
    return left;
}

template<typename T>
inline Rect<T> &operator*=(Rect<T> &left, const Rect<T> right)
{
    left.width *= right.width;
    left.height *= right.height;
    return left;
}

template<typename T>
inline Rect<T> &operator/=(Rect<T> &left, const Rect<T> right)
{
    left.width /= right.width;
    left.height /= right.height;
    return left;
}

template<typename T>
inline Rect<T> &operator%=(Rect<T> &left, const Rect<T> right)
{
    left.width %= right.width;
    left.height %= right.height;
    return left;
}

template<typename T>
inline bool operator!=(const Rect<T> &left, const Rect<T> &right)
{
    return left.left != right.left || left.top != right.top
        || left.width != right.width || left.height != right.height;
}

template<typename T>
inline bool operator==(const Rect<T> &left, const Rect<T> &right)
{
    return left.left == right.left && left.top == right.top
        && left.width == right.width && left.height == right.height;
}

template<typename T>
inline bool operator<(const Rect<T> &left, const Rect<T> &right)
{
    return left.width * left.height < right.width * right.height;
}

template<typename T>
inline bool operator>(const Rect<T> &left, const Rect<T> &right)
{
    return left.width * left.height > right.width * right.height;
}

template<typename T>
inline bool operator<=(const Rect<T> &left, const Rect<T> &right)
{
    return left.width * left.height <= right.width * right.height;
}

template<typename T>
inline bool operator>=(const Rect<T> &left, const Rect<T> &right)
{
    return left.width * left.height >= right.width * right.height;
}
