#include "enginepch.hpp"

BOOL APIENTRY DllMain(
    HMODULE module,
    DWORD  reason,
    LPVOID reserved
)
{
    UNREFERENCED_PARAMETER(module);
    UNREFERENCED_PARAMETER(reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
