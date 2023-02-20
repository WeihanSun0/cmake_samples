#pragma once


#ifdef _ENV_WIN // windows dll
#define DLLEXPORT extern "C" __declspec(dllexport)
namespace share_lib
{
    DLLEXPORT int __stdcall multiply(int a, int b);
} // namespace share_lib
#else // linux so
namespace share_lib
{
    extern "C" int multiply(int a, int b);
} // namespace share_lib
#endif