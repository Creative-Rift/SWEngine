/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Rect.inl
*/

template <typename T>
inline Rect<T>::Rect()
    :   left(0),
        top(0),
        width(0),
        height(0)
{}

template <typename T>
inline Rect<T>::Rect(T setLeft, T setTop, T setWidth, T setHeight)
    :   left(setLeft),
        top(setTop),
        width(setWidth),
        height(setHeight)
{}

template <typename T>
inline Rect<T>::Rect(const Vector2<T>& position, const Vector2<T>& size)
    :   left(position.x),
        top(position.y),
        width(size.x),
        height(size.y)
{}

template <typename T>
inline bool Rect<T>::contains(T x, T y) const
{
    if (x > left
    &&  y > top
    &&  x < left + width
    &&  y < top  + height)
        return (true);
    return (false);
}

template <typename T>
inline bool Rect<T>::contains(const Vector2<T>& point) const
{
    if (point.x > left
    &&  point.y > top
    &&  point.x < left + width
    &&  point.y < top  + height)
        return (true);
    return (false);
}

template <typename T>
inline bool Rect<T>::intersects(const Rect<T>& rectangle) const
{
    if (rectangle.left + rectangle.width  < left
    ||  rectangle.top  + rectangle.height < top
    ||  rectangle.left                    > left + width
    ||  rectangle.top                     > top  + height)
        return (false);
    return (true);
}

template <typename T>
inline Rect<T> operator+(const Rect<T>& left, const Rect<T> right)
{
    return (Rect<T>{left.left, left.top, left.width + right.width, left.height + right.height});
}

template <typename T>
inline Rect<T> operator-(const Rect<T>& left, const Rect<T> right)
{
    return (Rect<T>{left.left, left.top, left.width - right.width, left.height - right.height});
}

template <typename T>
inline Rect<T> operator*(const Rect<T>& left, const Rect<T> right)
{
    return (Rect<T>{left.left, left.top, left.width * right.width, left.height * right.height});
}

template <typename T>
inline Rect<T> operator/(const Rect<T>& left, const Rect<T> right)
{
    return (Rect<T>{left.left, left.top, left.width / right.width, left.height / right.height});
}

template <typename T>
inline Rect<T> operator%(const Rect<T>& left, const Rect<T> right)
{
    return (Rect<T>{left.left, left.top, left.width % right.width, left.height % right.height});
}

template <typename T>
inline Rect<T>& operator+=(Rect<T>& left, const Rect<T> right)
{
    left.width += right.width;
    left.height += right.height;
    return (left);
}

template <typename T>
inline Rect<T>& operator-=(Rect<T>& left, const Rect<T> right)
{
    left.width -= right.width;
    left.height -= right.height;
    return (left);
}

template <typename T>
inline Rect<T>& operator*=(Rect<T>& left, const Rect<T> right)
{
    left.width *= right.width;
    left.height *= right.height;
    return (left);
}

template <typename T>
inline Rect<T>& operator/=(Rect<T>& left, const Rect<T> right)
{
    left.width /= right.width;
    left.height /= right.height;
    return (left);
}

template <typename T>
inline Rect<T>& operator%=(Rect<T>& left, const Rect<T> right)
{
    left.width %= right.width;
    left.height %= right.height;
    return (left);
}

template <typename T>
inline bool operator!=(const Rect<T>& left, const Rect<T>& right)
{
    if (left.left   != right.left
    ||  left.top    != right.top
    ||  left.width  != right.width
    ||  left.height != right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator==(const Rect<T>& left, const Rect<T>& right)
{
    if (left.left   == right.left
    &&  left.top    == right.top
    &&  left.width  == right.width
    &&  left.height == right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator<(const Rect<T>& left, const Rect<T>& right)
{
    if (left.width * left.height < right.width * right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator>(const Rect<T>& left, const Rect<T>& right)
{
    if (left.width * left.height > right.width * right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator<=(const Rect<T>& left, const Rect<T>& right)
{
    if (left.width * left.height <= right.width * right.height)
        return (true);
    return (false);
}

template <typename T>
inline bool operator>=(const Rect<T>& left, const Rect<T>& right)
{
    if (left.width * left.height >= right.width * right.height)
        return (true);
    return (false);
}
