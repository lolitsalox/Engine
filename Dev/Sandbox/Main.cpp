#include <iostream>
#include "Logger.hpp"
#include "Sandbox.hpp"

int wmain()
{
    try
    {
        Engine::Logger::s_initalize();
        Sandbox::s_run();
    }
    catch (const std::exception& e)
    {
        std::wcout << L"Caught an exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::wcout << L"Caught an unknown exception\n";
    }
    return 0;
}
