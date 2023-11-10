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

            /// @brief Get location of a variable from a shader
            ///
            /// \param name name of the uniform variable
            /// \return location as int
            int getUniLocation(std::string &name) const;

        public:
            Shader(Shader const &) = delete;
            Shader(Shader &&) = delete;
            Shader &operator=(const Shader &other) = delete;
            Shader &operator=(Shader &&) = delete;

            /// @brief Default Constructor
            Shader();

            /// @brief Constructor with custom shader file
            ///
            /// \param fragment path to the fragment shader
            /// \param vertex path to the vertex shader
            Shader(std::string fragment, std::string vertex);

            /// @brief Default destructor
            ~Shader();

            /// @brief Create Opengl shader
            void createShader();

            /// @brief Define a shader file
            ///
            /// \param source path of the shader file
            /// \param type type of the shader
            /// \return Reference to the current shader
            Shader &setShaderSource(std::string source, ShaderFile::ShaderType type);

            /// @brief Get Opengl shader id
            ///
            /// \return unsigned int
            [[nodiscard]] const unsigned int &getId() const noexcept;

            /// @brief Check if shader is loaded
            ///
            /// \return boolean
            [[nodiscard]] bool isLoaded() const noexcept;

            /// @brief Define shader as active for Opengl
            void useShader() const;

            /// @brief Define boolean uniform variable
            ///
            /// \param varName uniform variable's name
            /// \param value boolean
            void setUniBool(std::string varName, bool &value) const;

            /// @brief Define int uniform variable
            ///
            /// \param varName uniform variable's name
            /// \param value int
            void setUniInt(std::string varName, int value) const;

            /// @brief Define float uniform variable
            ///
            /// \param varName uniform variable's name
            /// \param value float
            void setUniFloat(std::string varName, float value) const;

            /// @brief Define 4x4 matrix uniform variable
            ///
            /// \param varName uniform variable's name
            /// \param value 4x4 matrix
            void setUniMat4(std::string varName, const glm::mat4 &matrix) const;

            /// @brief Define Vector 3 uniform variable
            ///
            /// \param varName uniform variable's name
            /// \param value Vector 3
            void setUniFloat3(std::string varName, const float &v1, const float &v2, const float &v3) const;

            /// @brief Define Vector 3 uniform variable
            ///
            /// \param varName uniform variable's name
            /// \param value Vector 3
            void setUniFloat3(std::string varName, const Vector3f vector) const;

            /// @brief update Opengl shader information
            void update();
    }; // class Shader
} // SW

#endif //SHIPWRECK_ENGINE_SHADER_HPP
