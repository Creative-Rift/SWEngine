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
            /// @brief Default constructor
            VertexArray();

            /// @brief Default destructor
            ~VertexArray();

            /// @brief Update vertex array information on the graphical device
            void update();

            /// @brief Get vertex array object id
            ///
            /// \return unsigned int
            [[nodiscard]] const unsigned int &getVAO() const noexcept;

            /// @brief Get element buffer object id
            ///
            /// \return unsigned int
            [[nodiscard]] const unsigned int &getEBO() const noexcept;

            /// @brief Get element
            ///
            /// \param index
            /// \return Vertex's reference
            Vertex &operator[](std::size_t index);
    }; // class VertexArray

} // sw

#endif //SHIPWRECK_ENGINE_VERTEXARRAY_HPP
