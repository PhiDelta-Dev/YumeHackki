#include "PCH.h"

namespace ui
{
	void print_title()
	{
		PRINT(" --------------------");
		PRINT(" | Yume Hackki v1.0 |  by PhiDelta");
		PRINT(" --------------------\n");
	}

	void print_success_message() { PRINT("[SUCCESS] Yume Nikki was found!\n"); }
	void print_error_message() { PRINT("[ERROR] Yume Nikki was not found. Make sure to use the Steam version!\n"); }

	void print_menu_page_info(const ui8& page)
	{
		switch (page)
		{
		case 0: break;
		case 1: PRINT("New x coordinate [tiles]:"); break;
		case 2: PRINT("New y coordinate [tiles]:"); break;
		case 3: PRINT("New movement speed:"); break;
		case 4: PRINT("Noclip state [0 = disabled, 1 = enabled]:"); break;
		case 5: PRINT("New map [map id or -1 to disable]:"); break;
		default: break;
		}
	}

	void clear_prompt(Application& app)
	{
		system("cls");
		print_title();
		print_success_message();
		PRINT("Select an action:"
			"\n\t1: Set the x coordinate"
			"\n\t2: Set the y coordinate"
			"\n\t3: Set the movement speed"
			"\n\t4: Enable or disable noclip"
			"\n\t5: Set the current map (requires a map refresh)");
		app.MenuPage = 0;
	}

	void fetch_input(Application& app, ui16& input)
	{
		input = 0;
		std::cout << "> ";

		while (!(std::cin >> input))
		{
			std::cin.clear();
			std::cin.ignore(0xFFFF, '\n');

			ui::clear_prompt(app);

			input = 0;
			std::cout << "> ";
		}
	}

	void print_monoe()
	{
		PRINT((char)0xB0 << (char)0xB0 << (char)0xB0 << (char)0xB0 << (char)0xB0 << (char)0xB2 << (char)0xB0 << (char)0xB0);
		PRINT((char)0xB0 << (char)0xB0 << (char)0xB2 << (char)0xB0 << (char)0xB0 << (char)0xB2 << (char)0xB0 << (char)0xB0);
		PRINT((char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2);
		PRINT((char)0xB2 << (char)0xB0 << (char)0xB0 << (char)0xB2 << (char)0xB2 << (char)0xB0 << (char)0xB0 << (char)0xB2);
		PRINT((char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2);
		PRINT((char)0xB2 << (char)0xB2 << (char)0xB0 << (char)0xB2 << (char)0xB2 << (char)0xB0 << (char)0xB2 << (char)0xB2);
		PRINT(' ' << (char)0xB2 << (char)0xB2 << (char)0xB0 << (char)0xB0 << (char)0xB2 << (char)0xB2 << ' ');
		PRINT(' ' << ' ' << (char)0xB2 << (char)0xB2 << (char)0xB2 << (char)0xB2 << ' ' << ' ');
	}
}