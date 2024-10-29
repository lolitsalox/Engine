#pragma once

#include <sstream>
#include "Event.hpp"

namespace Engine
{
    class MouseMovedEvent : public Event
    {
    public:
        explicit MouseMovedEvent(const std::pair<float, float> mouse_position) :
            m_position(mouse_position) {}

        virtual ~MouseMovedEvent() = default;
        MouseMovedEvent(const MouseMovedEvent&) = delete;
        MouseMovedEvent& operator=(const MouseMovedEvent&) = delete;
        MouseMovedEvent(MouseMovedEvent&&) = delete;
        MouseMovedEvent& operator=(MouseMovedEvent&&) = delete;

        virtual std::string to_string() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: (" << m_position.first << ", " << m_position.second << ")";
            return ss.str();
        }

        std::pair<float, float> get_position() const { return m_position; }

    private:
        const std::pair<float, float> m_position;
    };

    class MouseScrollEvent : public Event
    {
    public:
        explicit MouseScrollEvent(const std::pair<float, float> mouse_offset) :
            m_offset(mouse_offset) {}

        virtual ~MouseScrollEvent() = default;
        MouseScrollEvent(const MouseScrollEvent&) = delete;
        MouseScrollEvent& operator=(const MouseScrollEvent&) = delete;
        MouseScrollEvent(MouseScrollEvent&&) = delete;
        MouseScrollEvent& operator=(MouseScrollEvent&&) = delete;

        virtual std::string to_string() const override
        {
            std::stringstream ss;
            ss << "MouseScrollEvent: (" << m_offset.first << ", " << m_offset.second << ")";
            return ss.str();
        }

        std::pair<float, float> get_offset() const { return m_offset; }

    private:
        const std::pair<float, float> m_offset;
    };
}
