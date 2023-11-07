/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Texture.hpp
*/

#ifndef SHIPWRECK_ENGINE_TEXTURE_HPP
#define SHIPWRECK_ENGINE_TEXTURE_HPP

#include <string>

#include "SWEngine.hpp"

namespace sw {
    class SW_MODULE_EXPORT Texture {
        public:
            /// @brief Default constructor
            ///
            /// \param path path to the texture's file
            explicit Texture(std::string path);

            /// @brief Default destructor
            ~Texture() = default;

            /// @brief Get the id of the texture (given by OpenGL)
            ///
            /// \return unsigned int
            [[nodiscard]] unsigned int getId() const;

            /// @brief Get the width of the texture
            ///
            /// \return int
            [[nodiscard]] int getWidth() const;

            /// @brief Get the height of the texture
            ///
            /// \return int
            [[nodiscard]] int getHeight() const;

            /// @brief Get number of channels
            ///
            /// \return int
            [[nodiscard]] int getChannels() const;

        private:
            int m_width;
            int m_height;
            int m_channels;
            unsigned char *m_data;
            unsigned int m_id;

            void upload();
    };
} // SW

#endif //SHIPWRECK_ENGINE_TEXTURE_HPP
