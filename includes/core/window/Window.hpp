/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Window.hpp
*/

#ifndef SHIPWRECK_ENGINE_WINDOW_HPP
#define SHIPWRECK_ENGINE_WINDOW_HPP

#include <string>

#include "SWEngine.hpp"
#define GLFW_INCLUDE_NONE
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

        /// @brief Create a window and define all default settings
        static void Start();

        /// @brief Close and destroy the window
        static void Close();

        /// @brief Swap buffers
        static void Update();

        /// @brief Toggle window state to fullscreen/windowed
        static void ToggleFullScreen();

        /// @brief Close Window and unload the context
        static void CloseWindow();

        /// @brief Set the windows state to Maximized is resizable
        static void Maximize();

        /// @brief Set the windows state to Minimized is resizable
        static void Minimize();

        /// @brief Set the windows state to default value
        static void Restore();

        /// @brief Request the current window to be focus
        static void RequestAttention();

        /// @brief Define new window title
        ///
        /// \param title std::string - new title
        static void SetTitle(std::string&& title);

        /// @brief Set current window to use flags
        ///
        /// \param flags Flag defined in sw::WindowFlag
        static void SetFlag(WindowFlags flags);

        /// @brief Clear the flag for the current window
        ///
        /// \param flags Flag defined in sw::WindowFlag
        static void ClearFlag(WindowFlags flags);

        /// @brief Define the window position
        ///
        /// \param x
        /// \param y
        static void SetWindowPos(int x, int y);

        /// @brief Define the window position
        ///
        /// \param pos - sw::Vector2i(int x, int y)
        static void SetWindowPos(sw::Vector2i pos);

        /// @brief Define the minimum size of the current window
        ///
        /// \param with
        /// \param height
        static void SetMinSize(int with, int height);

        /// @brief Define the minimum size of the current window
        ///
        /// \param size - sw::Vector2i(int x, int y)
        static void SetMinSize(sw::Vector2i size);

        /// @brief Define the maximum size of the current window
        ///
        /// \param with
        /// \param height
        static void SetMaxSize(int with, int height);

        /// @brief Define the maximum size of the current window
        ///
        /// \param size - sw::Vector2i(int x, int y)
        static void SetMaxSize(sw::Vector2i size);

        /// @brief Define the sze of the current window
        ///
        /// \param size - sw::Vector2i(int x, int y)
        static void SetSize(sw::Vector2i size);

        /// @brief Define the size of the current window
        ///
        /// \param with
        /// \param height
        static void SetSize(int with, int height);

        /// @brief Define the visibility of the cursor
        ///
        /// \param visible
        static void SetVisibleCursor(bool visible);

        /// @brief Enable or disable the cursor (lock/unlock)
        ///
        /// \param enable
        static void SetEnableCursor(bool enable);

        /// @brief Define the monitor where the window is displayed
        ///
        /// \param index
        static void SetMonitor(int index);

        /// @brief Set clipboard text content
        ///
        /// \param text
        static void SetClipboardText(std::string&& text);

        /// @brief Set the Opacity of the window
        ///
        /// \param opacity 0.0f - 1.0f
        static void SetOpacity(float opacity);
        // static void SetIcon(); @TODO add function when Texture is implemented

        /// @brief Get the size of the windows
        ///
        /// \return sw::Vector2i(width, height)
        static Vector2i GetSize();

        /// @brief Get the title of the current window
        ///
        /// \return std::string
        static std::string GetTitle();

        /// @brief Get the position of the current window
        ///
        /// \return sw::Vector2i(x, y)
        static Vector2i GetPosition();

        /// @brief Get Clipboard content
        ///
        /// \return std::string
        static std::string GetClipBoardText();

        /// @brief Get opacity of the current window
        ///
        /// \return float (0.0f - 1.0f)
        static float GetOpacity();

        /// @brief Check if the flag is set for the window
        ///
        /// \param flags Flag defined in sw::WindowFlag
        /// \return boolean
        static bool HasFlag(WindowFlags flags);

        /// @brief Get the windows and it's context
        ///
        /// \return GLFWwindow *
        static GLFWwindow *GetWindow();
        // static Vector2i GetDpi(); @TODO Add it later

        /// @brief Check if the window is in FullScreen mode
        ///
        /// \return boolean
        static bool IsFullScreen();

        /// @brief Check if the window is open
        ///
        /// \return boolean
        static bool IsOpen();

        /// @brief Check if the window is ready
        ///
        /// \return boolean
        static bool IsReady();

        /// @brief Check if the Cursor is visible
        ///
        /// \return boolean
        static bool IsCursorVisible();

        /// @brief Check if the window is hidden
        ///
        /// \return boolean
        static bool IsHidden();

        /// @brief Check if the window is Maximized
        ///
        /// \return boolean
        static bool isMaximized();

        /// @brief Check if the window is Minimized
        ///
        /// \return boolean
        static bool isMinimized();

        /// @brief Check if the window is focus
        ///
        /// \return boolean
        static bool IsFocus();

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
        static bool m_focus;
        static bool m_cursorOnScreen;

        static void SetUpCallBack();
        static void FocusCallback(GLFWwindow *window, int focus);
        static void CursorEnterCallback(GLFWwindow *window, int enter);
    };
} // sw

#endif //SHIPWRECK_ENGINE_WINDOW_HPP
