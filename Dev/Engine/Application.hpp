#include "enginepch.hpp"

namespace Engine
{
    class ENGINE_API Application
    {
    public:
        Application() = default;
        virtual ~Application() = default;
        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(Application&&) = delete;

    protected:
        void _run();
    };
}