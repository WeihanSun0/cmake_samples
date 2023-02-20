#include "share_lib.h"
#include <iostream>

namespace share_lib
{
#ifdef _ENV_WIN
    DLLEXPORT int __stdcall multiply(int a, int b)
    {
        return a * b;
    }
#else
    int multiply(int a, int b)
    {
        return a * b;
    }
#endif
}
