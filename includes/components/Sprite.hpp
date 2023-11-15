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
            /// \param gameObject - sw::GameObject
            explicit Sprite(sw::GameObject &gameObject);

            /// \brief Get the sprite's texture
            ///
            /// \return Shared pointer to the texture
            [[nodiscard]] std::shared_ptr<Texture> texture() const;

            /// \brief Define the texture
            ///
            /// \param texture Texture's Name
            /// \return A reference to the sprite
            Sprite &setTexture(std::string name);

            /// \brief Define a sub-rectangle of the texture displayed on the Sprite
            ///
            /// \param rect Dimension (width, height) of the rect
            /// \return A reference to the sprite
            Sprite &setTextureRect(sw::FloatRect rect);

            /// \brief Define a color (this color is multiplied with the texture pixels)
            ///
            /// \param color - sw::Color
            /// \return A reference to the sprite
            Sprite &setColor(const sw::Color &color);

            /// \brief Flip the texture on X axis. Flipped (true) not flipped (false)
            ///
            /// \param invert Boolean
            /// \return Reference to the Sprite
            Sprite &flipOnX(bool invert);

            /// \brief Flip the texture on Y axis. Flipped (true) not flipped (false)
            ///
            /// \param invert Boolean
            /// \return Reference to the Sprite
            Sprite &flipOnY(bool invert);

            /// \brief Get the value if the Sprite texture is flipped on X axis.
            /// Flipped (true) not flipped (false)
            ///
            /// \return Boolean
            [[nodiscard]] bool isFlippedX() const;

            /// \brief Get the value if the Sprite texture is flipped on Y axis.
            /// Flipped (true) not flipped (false)
            ///
            /// \return Boolean
            [[nodiscard]] bool isFlippedY() const;

            /// \brief Get the shader
            ///
            /// \return A Shared pointer to the Shader
            [[nodiscard]] std::shared_ptr<Shader> getShader() const noexcept;

            /// \brief Get the shader associated
            ///
            /// \return A reference to the Shader
            // [[nodiscard]] Material &getMaterial() noexcept;

            friend SpriteManager;
    }; // class Sprite

} // sw

#endif //SHIPWRECK_ENGINE_SPRITE_HPP
