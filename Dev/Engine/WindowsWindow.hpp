#pragma once

#include "Window.hpp"
#include "GLFW/glfw3.h"

namespace Engine
{
    class WindowsWindow : public Window
    {
    public:
        ENGINE_API WindowsWindow(const WindowProps& props);
        ENGINE_API virtual ~WindowsWindow() = default;
        WindowsWindow(const WindowsWindow&) = delete;
        WindowsWindow& operator=(const WindowsWindow&) = delete;
        WindowsWindow(WindowsWindow&&) = delete;
        WindowsWindow& operator=(WindowsWindow&&) = delete;

        ENGINE_API virtual void on_update() override;
        ENGINE_API virtual uint32_t get_width() const override;
        ENGINE_API virtual uint32_t get_height() const override;

    private:
        static GLFWwindow* _s_create_glfw_window(WindowProps* props);
        static void _s_glfw_error_callback(int error, const char* description);

    private:
        static uint32_t s_glfw_window_count;
        WindowProps m_props;
        GLFWwindow* m_window;
    };
}
