/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Vertex.hpp
*/

#ifndef SHIPWRECK_ENGINE_VERTEX_HPP
#define SHIPWRECK_ENGINE_VERTEX_HPP

#include "SWEngine.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace sw {
    class SW_MODULE_EXPORT Vertex {
        public:
            Vector3f position;
            Color color;
            Vector2f textureCoord;
            Vector3f normal;
            Vector3f bitangent;
            Vector3f tangent;

            Vertex();

            ~Vertex();

            explicit Vertex(Vector3f &position);

            Vertex(Vector3f &position, Vector2f &textureCoord);

            Vertex(Vector3f &position, Color &color);

            Vertex(Vector3f &position, Vector2f &textureCoord, Color &color);
    }; // class Vertex

#include "Vertex.inl"

} // SW

#endif //SHIPWRECK_ENGINE_VERTEX_HPP
