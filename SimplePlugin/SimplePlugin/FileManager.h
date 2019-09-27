#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "PluginSettings.h"

using std::ofstream;
using std::ios;
using std::ifstream;
//using std::to_string;

class PLUGIN_API FileManager
{
public:
	FileManager();
	~FileManager();

	void savePos(char* filePath, float* pos);
	void loadPos(char* filePath);
	float* getPos();

private:
	float* posArr = nullptr;
};