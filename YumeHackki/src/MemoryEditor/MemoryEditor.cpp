#include "PCH.h"

#define WINDOW_NAME L"YUME NIKKI"
#define PROCESS_NAME L"RPG_RT.exe"

namespace memory_editor
{
	void open_process(MemoryEditor& ed)
	{
		HWND window_handle = FindWindow(0, WINDOW_NAME);
		DWORD process_id;
		GetWindowThreadProcessId(window_handle, &process_id);
		ed.ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, 0, process_id);
		ed.ProcessBaseAddress = GetModuleBaseAddress(process_id, PROCESS_NAME);
	}

	void write_memory(MemoryEditor& ed, const ui64& address, const ui16& size, void* buffer)
	{
		DWORD old_protection;
		VirtualProtectEx(ed.ProcessHandle, (void*)(address), 4, PAGE_EXECUTE_READWRITE, &old_protection);
		WriteProcessMemory(ed.ProcessHandle, (void*)(address), buffer, size, 0);
	}

	void read_memory(MemoryEditor& ed, const ui64& address, const ui16& size, void* buffer)
	{ ReadProcessMemory(ed.ProcessHandle, (void*)(address), buffer, size, 0); }

	void write_memory_ptr(MemoryEditor& ed, const ui32* offsets, const ui8& offset_count, const ui16& size, void* buffer)
	{
		ui64 address = ed.ProcessBaseAddress;
		ui8 off = 0;

		while (off < offset_count - 1)
		{ read_memory(ed, address + offsets[off++], 4, &address); }
		write_memory(ed, address + offsets[off], size, buffer);
	}
}