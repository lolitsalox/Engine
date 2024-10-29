#include "enginepch.hpp"
#include "Event.hpp"

namespace Engine
{
    struct WindowProps
    {
        std::string title;
        uint32_t width;
        uint32_t height;

        WindowProps(const std::string& title = "Engine", 
            const uint32_t width = 1600, 
            const uint32_t height = 900)
            : title(title), width(width), height(height)
        {}
    };

    class Window
    {
    public:
        Window() = default;
        virtual ~Window() = default;
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(Window&&) = delete;

        virtual void on_update() = 0;
        virtual uint32_t get_width() const = 0;
        virtual uint32_t get_height() const = 0;
    };
}
