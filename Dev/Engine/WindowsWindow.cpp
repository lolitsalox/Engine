#include "enginepch.hpp"
#include "Logger.hpp"
#include <glad/glad.h>
#include "WindowEvent.hpp"
#include "WindowsWindow.hpp"

namespace Engine
{
    uint32_t WindowsWindow::s_glfw_window_count = 0;

    WindowsWindow::WindowsWindow(const WindowProps& props) :
		m_props(props),
        m_window(_s_create_glfw_window(&m_props))
    {
		glfwMakeContextCurrent(m_window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			ENGINE_CORE_ERROR("glad didnt load");
		}

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;
			
				WindowResizeEvent event(width, height);
				ENGINE_INFO(event.to_string());
				//data.event_callback(event);
			});
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow*)
			{
				WindowCloseEvent event;
				ENGINE_INFO(event.to_string());

				//data.event_callback(event);
			});

		/*
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.event_callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.event_callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, true);
					data.event_callback(event);
					break;
				}
				}
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				data.event_callback(event);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.event_callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.event_callback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.event_callback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.event_callback(event);
			});*/
    }

    void WindowsWindow::on_update()
    {
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(m_window);
    }

    uint32_t WindowsWindow::get_width() const
    {
        return 0;
    }

    uint32_t WindowsWindow::get_height() const
    {
        return 0;
    }

    GLFWwindow* WindowsWindow::_s_create_glfw_window(WindowProps* props)
    {
        ENGINE_CORE_INFO("Creating window {0} ({1}, {2})", props->title, props->width, props->height);

        if (0 == s_glfw_window_count)
        {
            int success = glfwInit();
            if (!success)
            {
                ENGINE_CORE_ERROR("Could not initialize GLFW!");
                throw std::exception("Could not initialize GLFW!");
            }
            glfwSetErrorCallback(_s_glfw_error_callback);
        }

        GLFWwindow* window = glfwCreateWindow(props->width, props->height, props->title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(window, props);
        ++s_glfw_window_count;




        return window;
    }

    void WindowsWindow::_s_glfw_error_callback(int error, const char* description)
    {
        ENGINE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }
}
