#pragma once

enum MenuPageId : ui8
{
	MENU_MAIN,

	MENU_HACK_SET_POS_X,
	MENU_HACK_SET_POS_Y,
	MENU_HACK_SET_SPEED,
	MENU_HACK_SET_NOCLIP,
	MENU_HACK_SET_MAP,
	MENU_HACK_SET_RNG_SEED,

	MENU_PAGE_COUNT
};

struct Application
{
	MemoryEditor MemEditor;

	ui8 Terminated = 0;
	ui8 MenuPage = 0;
};

namespace application
{
	void initialise(Application& app);
	void terminate(Application& app);
	void update(Application& app);
}