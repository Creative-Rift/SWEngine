/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Sprite.hpp
*/

#ifndef SHIPWRECK_ENGINE_SPRITE_HPP
#define SHIPWRECK_ENGINE_SPRITE_HPP

#include "SWEngine.hpp"
#include "base/Component.hpp"
#include "utils/Color.hpp"
#include "utils/VertexArray.hpp"
#include "utils/Rect.hpp"
#include "resources/Texture.hpp"
#include "utils/Shader.hpp"

namespace sw {

    class SpriteManager;

    class SW_MODULE_EXPORT Sprite : public Component {
        protected:
            VertexArray m_vertexArray;
            // Material m_material;
            std::shared_ptr<sw::Shader> m_shader;
            std::shared_ptr<Texture> m_texture;
            Color m_color;
            FloatRect m_rect;
            bool m_invertedX;
            bool m_invertedY;

        public:
            /// \brief Default constructor
            ///
            /// \param entityRef A reference to the entity that own the component
            explicit Sprite(sw::GameObject &gameObject);

            /// \brief Get the current texture associated to the sprite
            ///
            /// \return Reference to the texture
            [[nodiscard]] std::shared_ptr<Texture> texture() const;

            /// \brief Define the displayed texture
            ///
            /// \param texture Name of the texture
            ///
            /// \return A reference to the sprite
            Sprite &setTexture(std::string &name);

            /// \brief Define a rect displayed applied on the texture
            ///
            /// \param rect Dimension of the rect
            ///
            /// \return A reference to the sprite
            Sprite &setTextureRect(sw::FloatRect &rect);

            /// \brief Define a color (this color is multiplied with the texture pixels)
            ///
            /// \param color
            ///
            /// \return A reference to the sprite
            Sprite &setColor(const sw::Color &color);

            /// \brief Flip the texture on X axis
            ///
            /// \param invert Boolean that define if the texture is flipped (true) or not (false)
            /// \return Reference to the Sprite
            Sprite &flipOnX(bool invert);

            /// \brief Flip the texture on Y axis
            ///
            /// \param invert Boolean that define if the texture is flipped (true) or not (false)
            /// \return Reference to the Sprite
            Sprite &flipOnY(bool invert);

            /// \brief Get the value if the Sprite texture is flipped on X axis
            ///
            /// \return Boolean with the value true if he is flipped false otherwise
            [[nodiscard]] bool isFlippedX() const;

            /// \brief Get the value if the Sprite texture is flipped on Y axis
            ///
            /// \return Boolean with the value true if he is flipped false otherwise
            [[nodiscard]] bool isFlippedY() const;

            /// \brief Get the shader associated
            ///
            /// \return A reference to the Shader
            [[nodiscard]] std::shared_ptr<Shader> getShader() const noexcept;

            /// \brief Get the shader associated
            ///
            /// \return A reference to the Shader
            // [[nodiscard]] Material &getMaterial() noexcept;

            friend SpriteManager;
    }; // class Sprite

} // sw

#endif //SHIPWRECK_ENGINE_SPRITE_HPP
