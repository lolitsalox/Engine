#include "Logger.hpp"
#include "MouseEvent.hpp"
#include "WindowsWindow.hpp"
#include "Sandbox.hpp"

SandboxUPtr Sandbox::g_instance = nullptr;

void Sandbox::s_run()
{
    if (nullptr != g_instance)
    {
        ENGINE_ERROR("Sandbox already initialized");
        throw std::exception("Sandbox already initialized");
    }

    g_instance = std::unique_ptr<Sandbox>(new Sandbox());
    g_instance->_run();
}
