/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Shader.hpp
*/

#ifndef SHIPWRECK_ENGINE_SHADER_HPP
#define SHIPWRECK_ENGINE_SHADER_HPP

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "SWEngine.hpp"
#include "ShaderFile.hpp"
#include "Vector3.hpp"

namespace sw {
    class SW_MODULE_EXPORT Shader {
        private:
            unsigned int m_id;
            ShaderFile m_fragment;
            ShaderFile m_vertex;
            std::string m_fragmentPath;
            std::string m_vertexPath;
            int m_success;
            char m_info[512];
            bool m_loaded;

            int getUniLocation(std::string &name) const;

        public:
            void createShader();

            Shader(Shader const &) = delete;

            Shader(Shader &&) = delete;

            Shader();

            Shader(std::string fragment, std::string vertex);

            ~Shader();

            Shader &operator=(const Shader &other) = delete;

            Shader &operator=(Shader &&) = delete;

            Shader &setShaderSource(std::string source, ShaderFile::ShaderType type);

            [[nodiscard]] const unsigned int &getId() const noexcept;

            [[nodiscard]] bool isLoaded() const noexcept;

            void useShader() const;

            void setUniBool(std::string varName, bool &value) const;

            void setUniInt(std::string varName, int value) const;

            void setUniFloat(std::string varName, float value) const;

            void setUniMat4(std::string varName, const glm::mat4 &matrix) const;

            void setUniFloat3(std::string varName, const float &v1, const float &v2, const float &v3) const;

            void setUniFloat3(std::string varName, const Vector3f vector) const;

            void update();
    };
} // SW

#endif //SHIPWRECK_ENGINE_SHADER_HPP
