#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <functional>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
