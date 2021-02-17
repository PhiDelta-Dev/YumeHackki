#include "PCH.h"

si32 main()
{
	Application app;
	application::initialise(app);
	while (!app.Terminated) { application::update(app); }
	application::terminate(app);
	return 0;
}

namespace application
{
	void initialise(Application& app)
	{
		ui::print_title();
		memory_editor::open_process(app.MemEditor);
		if (app.MemEditor.ProcessHandle) { ui::print_success_message(); ui::clear_prompt(app); }
		else { app.Terminated = 1; ui::print_error_message(); }	
	}

	void terminate(Application& app) { std::cin.get(); }

	void update(Application& app)
	{
		ui::print_menu_page_info(app.MenuPage);

		ui16 input;
		ui::fetch_input(app, input);

		ui8 new_page = app.MenuPage;
		switch (app.MenuPage)
		{
		case MENU_MAIN:
			if (input == 0) { ui::print_monoe(); }
			else if (input < MENU_PAGE_COUNT) { new_page = (ui8)input; }
			else { ui::clear_prompt(app); }
			break;
		case MENU_HACK_SET_POS_X: hacks::set_pos_x(app.MemEditor, (ui32)input); break;
		case MENU_HACK_SET_POS_Y: hacks::set_pos_y(app.MemEditor, (ui32)input); break;
		case MENU_HACK_SET_SPEED: hacks::set_speed(app.MemEditor, (ui32)input); break;
		case MENU_HACK_SET_NOCLIP: hacks::set_noclip(app.MemEditor, (ui32)(input != 0)); break;
		case MENU_HACK_SET_MAP: hacks::set_map(app.MemEditor, (ui32)input); break;
		}

		if (app.MenuPage > MENU_MAIN) { ui::clear_prompt(app); }
		else{ app.MenuPage = new_page; }
	}
}