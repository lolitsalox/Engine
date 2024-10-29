#pragma once

#include "enginepch.hpp"
#include "spdlog/spdlog.h"
    
namespace Engine
{
    class Logger;
    using LoggerUPtr = std::unique_ptr<Logger>;
    using SpdLoggerPtr = std::shared_ptr<spdlog::logger>;

    class Logger
    {
    public:
        virtual ~Logger() = default;
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger& operator=(Logger&&) = delete;

        ENGINE_API static void s_initalize();
        inline static ENGINE_API spdlog::logger& s_get_core_logger() { return *g_logger->m_core_logger; };
        inline static ENGINE_API spdlog::logger& s_get_client_logger() { return *g_logger->m_client_logger; };

    private:
        Logger();
        
        static SpdLoggerPtr _s_create_logger(const std::string& name, const spdlog::level::level_enum level);

    private:
        static LoggerUPtr g_logger;
        const SpdLoggerPtr m_core_logger;
        const SpdLoggerPtr m_client_logger;
    };
}

// Core log macros
#define ENGINE_CORE_TRACE(...)  ::Engine::Logger::s_get_core_logger().trace(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)   ::Engine::Logger::s_get_core_logger().info(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)   ::Engine::Logger::s_get_core_logger().warn(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...)  ::Engine::Logger::s_get_core_logger().error(__VA_ARGS__)

// Client log macros
#define ENGINE_TRACE(...)   ::Engine::Logger::s_get_client_logger().trace(__VA_ARGS__)
#define ENGINE_INFO(...)    ::Engine::Logger::s_get_client_logger().info(__VA_ARGS__)
#define ENGINE_WARN(...)    ::Engine::Logger::s_get_client_logger().warn(__VA_ARGS__)
#define ENGINE_ERROR(...)   ::Engine::Logger::s_get_client_logger().error(__VA_ARGS__)
