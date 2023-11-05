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
            explicit Texture(std::string path);

            ~Texture() = default;

            [[nodiscard]] unsigned int getId() const;

            [[nodiscard]] int getWidth() const;

            [[nodiscard]] int getHeight() const;

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
