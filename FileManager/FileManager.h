#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include "FunctionsOfMenu.h"
using namespace std::filesystem;

class FileManager
{
	std::string string_path;
	path root;
public:
	FileManager()
	{
		string_path = "";
		root = "C:\\";
	}
	void explore_directory();
	void get_directory();
};

