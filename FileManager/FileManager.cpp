#include "FileManager.h"

void FileManager::explore_directory()
{
	get_directory();

	while (true)
	{
		std::cout << std::endl << root << ">";
		std::getline(std::cin, string_path);
		path temp = root;
		if (string_path == "exit") { exit(0); }
		else if (string_path == "menu") { FunctionsOfMenu::ShowMenu(); }
		else if (string_path == "help") { FunctionsOfMenu::Help(); }
		else if (string_path == "open") { FunctionsOfMenu::OpenFolderOrFile(); }

		root /= string_path;
		if (is_directory(root))
		{
			system("cls");
			get_directory();
		}
		else
		{
			root = temp;
		}
	}
}

void FileManager::get_directory()
{
	for (auto& file : directory_iterator(root))
	{
		std::cout << file.path() << std::endl;
	}
}
