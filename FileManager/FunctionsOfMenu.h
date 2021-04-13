#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Windows.h"
#include <conio.h>
#include <filesystem>

class FunctionsOfMenu
{
public:
	static void Help();
	static void Menu();
	static void GetHardDriveInfo();
	static void OpenMyComp();
	static void OpenNotepad();
	static void OpenFolderOrFile();
	static void RenameFile();
	static void Delete_File();
	static void ShowMenu();
};

