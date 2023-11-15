/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Vertex.inl
*/

inline Vertex::Vertex() :
position{0, 0, 0},
color{1.0f, 1.0f, 1.0f},
textureCoord{0, 0},
normal{0.0f, 1.0f, 0.0f},
bitangent{0.0f, 0.0f, 1.0f},
tangent{1.0f, 0.0f, 0.0f}
{}

inline Vertex::~Vertex()
= default;

inline Vertex::Vertex(Vector3f& position) :
position {position.x, position.y, position.z},
color {1.0f, 1.0f, 1.0f, 1.0f},
textureCoord {0, 0},
normal{0.0f, 1.0f, 0.0f},
bitangent{0.0f, 0.0f, 0.0f},
tangent{0.0f, 0.0f, 0.0f}
{}

inline Vertex::Vertex(Vector3f& position, Vector2f& textureCoord) :
position {position.x, position.y, position.z},
textureCoord {textureCoord.x, textureCoord.y},
color {255, 255, 255},
normal{0.0f, 1.0f, 0.0f},
bitangent{0.0f, 0.0f, 0.0f},
tangent{0.0f, 0.0f, 0.0f}
{}

inline Vertex::Vertex(Vector3f position, Color color) :
position {position.x, position.y, position.z },
color {color.r, color.g, color.b, color.a },
textureCoord {0, 0},
normal{0.0f, 1.0f, 0.0f},
bitangent{0.0f, 0.0f, 0.0f},
tangent{0.0f, 0.0f, 0.0f}
{}

inline Vertex::Vertex(Vector3f& position, Vector2f& textureCoord, Color& color) :
position {position.x, position.y, position.z},
color {color.r, color.g, color.b, color.a},
textureCoord {textureCoord.x, textureCoord.y},
normal{0.0f, 1.0f, 0.0f},
bitangent{0.0f, 0.0f, 0.0f},
tangent{0.0f, 0.0f, 0.0f}
{}
