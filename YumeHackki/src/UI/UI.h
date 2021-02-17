#pragma once

struct Application;

namespace ui
{
	void print_title();
	void print_success_message();
	void print_error_message();
	void print_menu_page_info(const ui8& page);
	void print_monoe();

	void clear_prompt(Application& app);

	void fetch_input(Application& app, ui16& input);
}