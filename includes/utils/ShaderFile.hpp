/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ShaderFile.hpp
*/

#ifndef SHIPWRECK_ENGINE_SHADERFILE_HPP
#define SHIPWRECK_ENGINE_SHADERFILE_HPP

#include <string>

#include "SWEngine.hpp"

#include "glad/glad.h"

namespace sw {
    class SW_MODULE_EXPORT ShaderFile {
        public:
            enum ShaderType {
                VERTEX = GL_VERTEX_SHADER,
                FRAGMENT = GL_FRAGMENT_SHADER
            };

            explicit ShaderFile(std::string shaderFile, ShaderType type);

            void compile();

            [[nodiscard]] const std::string &getShader() const noexcept;

            [[nodiscard]] const unsigned int &getId() const noexcept;

        private:
            std::string m_shaderContent;
            unsigned int m_id;
            int m_success;
            char m_info[512];
            ShaderType m_type;
    }; //class ShaderFile
} // SW

#endif //SHIPWRECK_ENGINE_SHADERFILE_HPP
