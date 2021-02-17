#pragma once

#include <Windows.h>
#include <TlHelp32.h>

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);