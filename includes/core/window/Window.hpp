/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Window.hpp
*/

#ifndef SHIPWRECK_ENGINE_WINDOW_HPP
#define SHIPWRECK_ENGINE_WINDOW_HPP

#include <string>

#include "SWEngine.hpp"
#include "GLFW/glfw3.h"
#include "utils/Vector2.hpp"

namespace sw
{
    enum WindowFlags {
        FULLSCREEN_MODE = 0x00000002,
        RESIZABLE       = 0x00000004,
        UNDECORATED     = 0x00000008,
        HIDDEN          = 0x00000010,
        MINIMIZED       = 0x00000020,
        MAXIMIZED       = 0x00000040,
        UNFOCUSED       = 0x00000080,
        TRANSPARENT     = 0x00000100,
    };

    class SW_MODULE_EXPORT Window {
    public:
        static void Start();
        static void Close();
        static void Update();

        static void ToggleFullScreen();
        static void CloseWindow();
        static void Maximize();
        static void Minimize();
        static void Restore();
        static void SetTitle(std::string&& title);
        static void SetFlag(WindowFlags flags);
        static void ClearFlag(WindowFlags flags);
        static void SetWindowPos(int x, int y);
        static void SetWindowPos(sw::Vector2i pos);
        static void SetMinSize(int with, int height);
        static void SetMinSize(sw::Vector2i size);
        static void SetMaxSize(int with, int height);
        static void SetMaxSize(sw::Vector2i size);
        static void SetSize(sw::Vector2i size);
        static void SetSize(int with, int height);
        static void SetVisibleCursor(bool visible);
        static void SetEnableCursor(bool enable);
        static void SetMonitor(int index);
        static void SetClipboardText(std::string&& text);

        static Vector2i GetSize();
        static std::string GetTitle();
        static Vector2i GetPosition();
        static std::string GetClipBoardText();
        static bool HasFlag(WindowFlags flags);
        static GLFWwindow *GetWindow();

        static bool IsFullScreen();
        static bool IsOpen();
        static bool IsReady();
        static bool IsCursorVisible();

    private:
        static GLFWwindow *m_window;

        static Vector2i m_size;
        static Vector2i m_maxSize;
        static Vector2i m_position;
        static std::string m_title;
        static bool m_fullScreen;
        static bool m_cursorHidden;
        static unsigned int m_flags;
        static bool m_ready;

        static void SetUpCallBack();
    };
} // sw

#endif //SHIPWRECK_ENGINE_WINDOW_HPP
