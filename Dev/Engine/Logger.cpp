#include "enginepch.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Logger.hpp"

namespace Engine
{
    LoggerUPtr Logger::g_logger = nullptr;

    Logger::Logger() :
        m_core_logger(_s_create_logger("ENGINE", spdlog::level::trace)),
        m_client_logger(_s_create_logger("APP", spdlog::level::trace))
    {}

    void Logger::s_initalize()
    {
        if (nullptr != g_logger)
        {
            throw std::exception("Already intialized logger");
        }
        g_logger = std::unique_ptr<Logger>(new Logger());
        
        spdlog::set_pattern("%^[%T] %n: %v%$");
    }

    SpdLoggerPtr Logger::_s_create_logger(const std::string& name, const spdlog::level::level_enum level)
    {
        SpdLoggerPtr logger = spdlog::stdout_color_mt(name);
        logger->set_level(level);
        return logger;
    }
}
