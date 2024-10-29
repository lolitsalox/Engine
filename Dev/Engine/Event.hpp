#pragma once

#include "enginepch.hpp"

namespace Engine
{
    class Event
    {
    public:
        Event() = default;
        virtual ~Event() = default;
        Event(const Event&) = delete;
        Event& operator=(const Event&) = delete;
        Event(Event&&) = delete;
        Event& operator=(Event&&) = delete;

        virtual std::string to_string() const = 0;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.to_string();
    }
}
