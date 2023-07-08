// Defines the entry point for the DLL application.

#include "pch.h"
#include "framework.h"

#include "math.hpp"
#define _math

#include "interface.cpp"
#define _interface

BOOL APIENTRY DllMain( HMODULE hModule , DWORD  ul_reason_for_call , LPVOID lpReserved ) {

    switch (ul_reason_for_call) {

        case DLL_PROCESS_ATTACH: break;

        case DLL_THREAD_ATTACH: break;

        case DLL_THREAD_DETACH: break;

        case DLL_PROCESS_DETACH: {
            
        } break;

    }

    return TRUE;

}

