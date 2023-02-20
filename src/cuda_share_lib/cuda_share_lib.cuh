#pragma once

#include <stdio.h>

#ifdef _ENV_WIN // windows dll
#ifdef CUDAPDELL32_EXPORTS
#define CUDADLL32_API __declspec(dllexport)
#else
#define CUDADLL32_API __declspec(dllimport)
#endif

extern "C" CUDADLL32_API void useCUDA_share();
#else
extern "C" void useCUDA_share();
#endif
