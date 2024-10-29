#include "Application.hpp"
#include "WindowsWindow.hpp"

namespace Engine
{
    void Application::_run()
    {
        WindowProps props;
        WindowsWindow window(props);
        while (true)
        {
            window.on_update();
        }
    }
}
