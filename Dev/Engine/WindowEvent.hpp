#pragma once

#include <sstream>
#include "Event.hpp"

namespace Engine
{
    class WindowResizeEvent : public Event
    {
    public:
        explicit WindowResizeEvent(const uint32_t width, const uint32_t height) :
            m_width(width),
            m_height(height)
        {}

        virtual ~WindowResizeEvent() = default;
        WindowResizeEvent(const WindowResizeEvent&) = delete;
        WindowResizeEvent& operator=(const WindowResizeEvent&) = delete;
        WindowResizeEvent(WindowResizeEvent&&) = delete;
        WindowResizeEvent& operator=(WindowResizeEvent&&) = delete;

        virtual std::string to_string() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << m_width << ", " << m_height << ")";
            return ss.str();
        }

        uint32_t get_width() const { return m_width; }
        uint32_t get_height() const { return m_height; }

    private:
        const uint32_t m_width;
        const uint32_t m_height;
    };


    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;
        virtual ~WindowCloseEvent() = default;
        WindowCloseEvent(const WindowCloseEvent&) = delete;
        WindowCloseEvent& operator=(const WindowCloseEvent&) = delete;
        WindowCloseEvent(WindowCloseEvent&&) = delete;
        WindowCloseEvent& operator=(WindowCloseEvent&&) = delete;

        virtual std::string to_string() const override { return "WindowCloseEvent"; }
    };
}
