#pragma once

struct MemoryEditor
{
	HANDLE ProcessHandle;
    ui64 ProcessBaseAddress;
};

namespace memory_editor
{
	void open_process(MemoryEditor& ed);

	void write_memory(MemoryEditor& ed, const ui64& address, const ui16& size, void* buffer);
	void read_memory(MemoryEditor& ed, const ui64& address, const ui16& size, void* buffer);

	void write_memory_ptr(MemoryEditor& ed, const ui32* offsets, const ui8& offset_count, const ui16& size, void* buffer);
}