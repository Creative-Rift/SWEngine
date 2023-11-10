/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Color.inl
*/

constexpr sw::Color::Color() :
r(0),
g(0),
b(0),
a(255)
{}

constexpr sw::Color::Color(float red, float green, float blue, float alpha) :
r(red),
g(green),
b(blue),
a(alpha)
{}

constexpr sw::Color::Color(int red, int green, int blue, int alpha) :
r(red),
g(green),
b(blue),
a(alpha)
{}

inline Color Color::normalize()
{
    return {r / 255, r / 255, r / 255, r / 255};
}
