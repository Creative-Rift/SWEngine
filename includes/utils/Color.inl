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
