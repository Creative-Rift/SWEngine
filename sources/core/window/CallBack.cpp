/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: CallBack.cpp
*/

#include "core/window/Window.hpp"

void sw::Window::SetUpCallBack()
{
    glfwSetWindowFocusCallback(m_window, &sw::Window::FocusCallback);
    glfwSetCursorEnterCallback(m_window, &sw::Window::CursorEnterCallback);
}

void sw::Window::FocusCallback(GLFWwindow *window, int focus)
{
    m_focus = focus != 0;
}

void sw::Window::CursorEnterCallback(GLFWwindow *window, int enter)
{
    m_cursorOnScreen = enter != 0;
}