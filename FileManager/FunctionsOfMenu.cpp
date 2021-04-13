#include "FunctionsOfMenu.h"
#include "FileManager.h"

void FunctionsOfMenu::GetHardDriveInfo()
{
	space_info _space = space("C:\\");
	std::cout << " Total size of the filesystem\t" << _space.capacity << " (in bytes) / " << _space.capacity / 1024 / 1024 / 1024 << " (in gb)" << std::endl;
	std::cout << " Free space\t" << _space.free << " (in bytes) / " << _space.free / 1024 / 1024 / 1024 << " (in gb)" << std::endl << std::endl;

	system("dir C:\\");
}

void FunctionsOfMenu::Help()
{
	std::string help = "help.txt";
	std::ifstream in;

	in.open(help);
	if (!in.is_open())
	{
		std::cout << "Error. File is missing!";
	}
	else
	{
		while (!in.eof())
		{
			std::getline(in, help);
			std::cout << help << std::endl;
		}
	}
}

void FunctionsOfMenu::Menu()
{
	std::string menu = "menu.txt";
	std::ifstream in;

	in.open(menu);
	if (!in.is_open())
	{
		std::cout << "Error. File is missing!";
	}
	else
	{
		while (!in.eof())
		{
			std::getline(in, menu);
			std::cout << menu << std::endl;
		}
	}
}

void FunctionsOfMenu::OpenMyComp()
{
	WinExec("C:\\WINDOWS\\explorer.exe", SW_SHOW);
}

void FunctionsOfMenu::OpenNotepad()
{
	WinExec("C:\\WINDOWS\\notepad.exe", SW_SHOW);
}

void FunctionsOfMenu::OpenFolderOrFile()
{
	std::wstring str;
	std::cout << "Example: C:\\Windows, C:\\Windows\\explorer.exe" << std::endl 
		<< "\t C:\\Program Files\\Internet Explorer, C:\\Program Files\\Internet Explorer\\iexplore.exe" << std::endl << std::endl;
	std::cout << "Press ENTER to open the directory where the executable file is located!" << std::endl << std::endl;
	std::cout << "Enter path to folder or file (with mask): ";
	std::getline(std::wcin, str);
	LPCWSTR temp = str.c_str();
	HWND f = NULL;
	ShellExecute(f, NULL, temp, NULL, NULL, SW_SHOWNORMAL);
}

void FunctionsOfMenu::RenameFile()
{
	std::cout << std::endl << " Enter file or folder name (with full path and mask for file): ";

	std::string filename_1;
	std::string filename_2;

	std::getline(std::cin, filename_1);
	std::cout << " Enter new name: ";
	std::getline(std::cin, filename_2);

	bool ok = std::rename(filename_1.c_str(), filename_2.c_str());
	if (ok)
	{
		std::cout << "File rename" << std::endl;
		Sleep(3000);
	}
	else
	{
		std::cout << "File not rename" << std::endl;
		Sleep(3000);
	}
}

void FunctionsOfMenu::Delete_File()
{
	std::cout << std::endl << " Enter file or folder name (with full path and mask for file): ";

	std::string filename;
	std::getline(std::cin, filename);
	bool ok = remove(filename);
	if (ok)
	{
		std::cout << "File remove" << std::endl;
		Sleep(3000);
	}
	else
	{
		std::cout << "File not remove" << std::endl;
		Sleep(3000);
	}
}

void FunctionsOfMenu::ShowMenu()
{
	int choise = 0;
	while (true)
	{
		system("cls");
		Menu();
		choise = _getch();
		switch (choise)
		{
		case 48: //0
			Help();
			_getch();
			break;

		case 49: //1
		{
			system("cls");
			FileManager fm;
			fm.explore_directory();
			break;
		}

		case 50: //2
			system("cls");
			GetHardDriveInfo();
			_getch();
			break;

		case 51: //3
			OpenMyComp();
			break;

		case 52: //4
			OpenNotepad();
			break;

		case 53: //5			
		{
			OpenFolderOrFile(); 
			break;
		}

		case 54: //6
		{
			RenameFile(); 
			break;
		}

		case 55: //7
		{
			Delete_File();
			break;
		}

		case 27: //Esc
			exit(0);
			break;
		}
	}
}

