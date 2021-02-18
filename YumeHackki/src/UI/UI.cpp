#include "PCH.h"

#define CH_D (char)0xB0
#define CH_L (char)0xB2

namespace ui
{
	void print_title()
	{
		PRINT(" --------------------"
			"\n | Yume Hackki v1.0 |  by PhiDelta"
			"\n --------------------\n");
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
		PRINT(
			CH_D << CH_D << CH_D << CH_D << CH_D << CH_L << CH_D << CH_D << '\n' <<
			CH_D << CH_D << CH_L << CH_D << CH_D << CH_L << CH_D << CH_D << '\n' <<
			CH_L << CH_L << CH_L << CH_L << CH_L << CH_L << CH_L << CH_L << '\n' <<
			CH_L << CH_D << CH_D << CH_L << CH_L << CH_D << CH_D << CH_L << '\n' <<
			CH_L << CH_L << CH_L << CH_L << CH_L << CH_L << CH_L << CH_L << '\n' <<
			CH_L << CH_L << CH_D << CH_L << CH_L << CH_D << CH_L << CH_L << '\n' <<
			' '  << CH_L << CH_L << CH_D << CH_D << CH_L << CH_L << ' '  << '\n' <<
			' '  << ' '  << CH_L << CH_L << CH_L << CH_L
		);
	}
}