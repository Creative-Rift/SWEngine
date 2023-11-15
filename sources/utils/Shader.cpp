/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Shader.cpp
*/

#include <iostream>

#include "utils/exception/Error.hpp"
#include "glad/glad.h"

#include "utils/Shader.hpp"

const std::string defaultFragmentShader = "#version 460 core\n"
                                  "out vec4 FragColor;\n"
                                  "\n"
                                  "in vec4 ourColor;\n"
                                  "in vec2 TexCoord;\n"
                                  "\n"
                                  "uniform sampler2D ourTexture;\n"
                                  "uniform int hasTexture;\n"
                                  "\n"
                                  "void main()\n"
                                  "{\n"
                                  "    if (hasTexture == 0) {\n"
                                  "        FragColor = ourColor;\n"
                                  "    } else {\n"
                                  "        vec4 texColor = texture(ourTexture, TexCoord);\n"
                                  "        if(texColor.a < 0.1)\n"
                                  "            discard;\n"
                                  "        FragColor = ourColor * texColor;\n"
                                  "    }\n"
                                  "}";

const std::string defaultVertexShader = "#version 460 core\n"
                                        "\n"
                                        "layout (location = 0) in vec3 aPos;\n"
                                        "layout (location = 1) in vec4 aColor;\n"
                                        "layout (location = 2) in vec2 aTexCoord;\n"
                                        "\n"
                                        "uniform mat4 model;         // Transform\n"
                                        "uniform mat4 view;          // camera pos\n"
                                        "uniform mat4 projection;    // Ortho or projection\n"
                                        "\n"
                                        "out vec4 ourColor;\n"
                                        "out vec2 TexCoord;\n"
                                        "\n"
                                        "void main()\n"
                                        "{\n"
                                        "    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
                                        "    ourColor = aColor;\n"
                                        "    TexCoord = aTexCoord;\n"
                                        "}";

sw::Shader::Shader() :
m_id(0),
m_fragment(defaultFragmentShader, sw::ShaderFile::FRAGMENT),
m_vertex(defaultVertexShader, sw::ShaderFile::VERTEX),
m_fragmentPath(""),
m_vertexPath(""),
m_success(),
m_info(),
m_loaded(false)
{
    createShader();
}

sw::Shader::Shader(std::string fragment, std::string vertex) :
m_id(0),
m_fragmentPath(fragment),
m_vertexPath(vertex),
m_fragment(fragment, sw::ShaderFile::FRAGMENT),
m_vertex(vertex, sw::ShaderFile::VERTEX),
m_success(),
m_info(),
m_loaded(false)
{
    createShader();
}

sw::Shader::~Shader()
{
    glDeleteProgram(m_id);
}

const unsigned int &sw::Shader::getId() const noexcept
{
    return (m_id);
}

bool sw::Shader::isLoaded() const noexcept
{
    return (m_loaded);
}

void sw::Shader::useShader() const
{
    glUseProgram(getId());
}

sw::Shader &sw::Shader::setShaderSource(std::string source, sw::ShaderFile::ShaderType type)
{
    if (type == sw::ShaderFile::FRAGMENT) {
        glDetachShader(m_id, m_fragment.getId());
        m_fragment = sw::ShaderFile(source, type);
        glAttachShader(m_id, m_fragment.getId());
        m_fragmentPath = source;
    }
    else {
        glDetachShader(m_id, m_vertex.getId());
        m_vertex = sw::ShaderFile(source, type);
        glAttachShader(m_id, m_vertex.getId());
        m_vertexPath = source;
    }
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &m_success);
    if (!m_success) {
        glGetProgramInfoLog(m_id, 512, nullptr, m_info);
        std::cerr << "ERROR: shader linking [" << source << "]: " << m_info << std::endl;
    }
    return (*this);
}

int sw::Shader::getUniLocation(std::string &name) const
{
    int result = glGetUniformLocation(m_id, name.c_str());

    if (result == -1)
        throw sw::Error("Uniform shader variable not found: " + name);
    return (result);
}

void sw::Shader::setUniBool(std::string varName, bool &value) const
{
    glUniform1i(getUniLocation(varName), value);
}

void sw::Shader::setUniInt(std::string varName, int value) const
{
    glUniform1i(getUniLocation(varName), value);
}

void sw::Shader::setUniFloat(std::string varName, float value) const
{
    glUniform1f(getUniLocation(varName), value);
}

void sw::Shader::setUniMat4(std::string varName, const glm::mat4 &matrix) const
{
    glUniformMatrix4fv(getUniLocation(varName), 1, GL_FALSE, glm::value_ptr(matrix));
}

void sw::Shader::setUniFloat3(std::string varName, const float &v1, const float &v2, const float &v3) const
{
    glUniform3f(getUniLocation(varName), v1, v2, v3);
}

void sw::Shader::setUniFloat3(std::string varName, const sw::Vector3f vector) const
{
    glUniform3f(getUniLocation(varName), vector.x, vector.y, vector.z);
}

void sw::Shader::createShader()
{
    m_id = glCreateProgram();
    m_fragment.compile();
    m_vertex.compile();
    glAttachShader(m_id, m_fragment.getId());
    glAttachShader(m_id, m_vertex.getId());
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &m_success);
    if (!m_success) {
        glGetProgramInfoLog(m_id, 512, nullptr, m_info);
        throw sw::Error("ERROR: shader linking: " + std::string(m_info));
    }
}

void sw::Shader::update()
{
    glAttachShader(m_id, m_fragment.getId());
    glAttachShader(m_id, m_vertex.getId());
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &m_success);
    if (!m_success) {
        glGetProgramInfoLog(m_id, 512, nullptr, m_info);
        std::cerr << "ERROR: shader linking: " << m_info << std::endl;
    }
}