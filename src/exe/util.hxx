#pragma once

#include <QString>

#ifdef _WIN32
    #include "windows.h"
    #define isWindows() true
#else 
    #define isWindows() false
#endif

namespace {
    Qt::WindowFlags defaultWindowFlags = Qt::WindowFlags() 
//        | Qt::MSWindowsFixedSizeDialogHint
//        | Qt::X11BypassWindowManagerHint
//        | Qt::FramelessWindowHint
//        | Qt::NoDropShadowWindowHint
//        | Qt::WindowTitleHint
//        | Qt::WindowSystemMenuHint
//        | Qt::WindowMinimizeButtonHint
//        | Qt::WindowMaximizeButtonHint
//        | Qt::WindowCloseButtonHint
//        | Qt::WindowContextHelpButtonHint
//        | Qt::WindowShadeButtonHint
//        | Qt::WindowStaysOnTopHint
//        | Qt::WindowStaysOnBottomHint
//        | Qt::CustomizeWindowHint
;

}

QString fileToBase64 ( QString source );