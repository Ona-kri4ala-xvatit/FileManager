#include <iostream>
#include <string>
#include "Console.h"
#include "FunctionsOfMenu.h"
#include "FileManager.h"

int main()
{
	Console::front_and_backgroud_color();
	Console::front_and_size();

	FunctionsOfMenu::Help();
	std::cout << std::endl << std::endl << "  To continue press any key";
	_getch();
	system("cls");

	FileManager file_manager;
	file_manager.explore_directory();

	//auto result = create_directory("test"); //создать папку

	/*bool makeDir(const char* dir)
	{
		if (exists(dir))
			return is_directory(status(dir));
		else
			return create_directories(dir);
	}*/



	return 0;
}
