/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ShaderFile.cpp
*/

#include <fstream>
#include <sstream>

#include "glad/glad.h"
#include "utils/ShaderFile.hpp"
#include "utils/exception/Error.hpp"

sw::ShaderFile::ShaderFile(std::string shaderFile, sw::ShaderFile::ShaderType type) :
        m_shaderContent{},
        m_id{0},
        m_success{},
        m_info{},
        m_type{type}
{
    std::fstream file(shaderFile);
    if (file.is_open()) {
        std::stringstream ss;
        ss << file.rdbuf();
        m_shaderContent = ss.rdbuf()->str();
    } else
        m_shaderContent = shaderFile;
    file.close();
}

void sw::ShaderFile::compile()
{
    char *str = m_shaderContent.data();

    if (m_id == 0)
        m_id = glCreateShader(m_type);
    glShaderSource(m_id, 1, &str, nullptr);
    glCompileShader(m_id);
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &m_success);
    if (!m_success) {
        glGetShaderInfoLog(m_id, 512, nullptr, m_info);
        throw sw::Error("Error Shader couldn't compile: " + std::string(m_info));
    }
}

const std::string &sw::ShaderFile::getShader() const noexcept
{
    return (m_shaderContent);
}

const unsigned int &sw::ShaderFile::getId() const noexcept
{
    return (m_id);
}