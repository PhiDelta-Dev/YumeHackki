#pragma once

namespace hacks
{
	void set_pos_x(MemoryEditor& ed, const ui32& x);
	void set_pos_y(MemoryEditor& ed, const ui32& y);
	void set_speed(MemoryEditor& ed, const ui32& speed);
	void set_noclip(MemoryEditor& ed, const ui32& state);
	void set_map(MemoryEditor& ed, const ui32& id);
	void set_rng_seed(MemoryEditor& ed, const ui32& seed);
}