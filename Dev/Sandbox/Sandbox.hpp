#pragma once

#include "Application.hpp"

class Sandbox;
using SandboxUPtr = std::unique_ptr<Sandbox>;

class Sandbox : public Engine::Application
{
public:
    virtual ~Sandbox() = default;
    Sandbox(const Sandbox&) = delete;
    Sandbox& operator=(const Sandbox&) = delete;
    Sandbox(Sandbox&&) = delete;
    Sandbox& operator=(Sandbox&&) = delete;

    static void s_run();

private:
    Sandbox() = default;

private:
    static SandboxUPtr g_instance;
};
