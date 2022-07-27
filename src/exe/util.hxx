#pragma once

#ifdef _WIN32
    #include "windows.h"
    #define isWindows() true
#else 
    #define isWindows() false
#endif