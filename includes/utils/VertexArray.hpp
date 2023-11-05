/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: VertexArray.hpp
*/

#ifndef SHIPWRECK_ENGINE_VERTEXARRAY_HPP
#define SHIPWRECK_ENGINE_VERTEXARRAY_HPP

#include <vector>

#include "SWEngine.hpp"
#include "Vertex.hpp"

namespace sw {

    class SW_MODULE_EXPORT VertexArray {
        private:
            unsigned int m_vbo;
            unsigned int m_vao;
            unsigned int m_ebo;
            std::vector <Vertex> m_array;
            unsigned int m_indices[6];
        public:
            VertexArray();

            ~VertexArray();

            void update();

            [[nodiscard]] const unsigned int &getVAO() const noexcept;

            [[nodiscard]] const unsigned int &getEBO() const noexcept;

            Vertex &operator[](std::size_t index);
    }; // class VertexArray

} // sw

#endif //SHIPWRECK_ENGINE_VERTEXARRAY_HPP
