#include "PCH.h"

namespace hacks
{
	void set_pos_x(MemoryEditor& ed, const ui32& x)
	{
		ui32 offsets[] = { 0xD2014, 0x14 };
		ui32 buffer = x;

		memory_editor::write_memory_ptr(ed, offsets, sizeof(offsets) / 4, 4, &buffer);
	}

	void set_pos_y(MemoryEditor& ed, const ui32& y)
	{
		ui32 offsets[] = { 0xD2014, 0x18 };
		ui32 buffer = y;

		memory_editor::write_memory_ptr(ed, offsets, sizeof(offsets) / 4, 4, &buffer);
	}

	void set_speed(MemoryEditor& ed, const ui32& speed)
	{
		ui32 offsets[] = { 0xD2014, 0x38 };
		ui32 buffer = speed;

		memory_editor::write_memory_ptr(ed, offsets, sizeof(offsets) / 4, 4, &buffer);
	}

	void set_noclip(MemoryEditor& ed, const ui32& state)
	{
		ui32 offsets[] = { 0xD2014, 0x4A };
		ui32 buffer = state * 0x00010001;

		memory_editor::write_memory_ptr(ed, offsets, sizeof(offsets) / 4, 4, &buffer);
	}

	void set_map(MemoryEditor& ed, const ui32& id)
	{
		ui64 address = ed.ProcessBaseAddress + 0xC0F9E;
		ui32 buffer[3];
		if (id <= 179)
		{
			buffer[0] = 0x1040C7EC;
			buffer[1] = id;
			buffer[2] = 0x50899090;
		}
		else
		{
			buffer[0] = 0x105089EC;
			buffer[1] = 0x8B144889;
			buffer[2] = 0x50890855;
		}

		memory_editor::write_memory(ed, address, sizeof(buffer), &buffer[0]);
	}
}