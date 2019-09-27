#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

void FileManager::savePos(char* filePath, float* pos)
{
	ofstream file(filePath, ios::out, ios::binary);

	if (file.is_open()) 
	{
		//file.write(reinterpret_cast<char*>(&pos[0]), sizeof(float));
		//file.write(reinterpret_cast<char*>(&pos[1]), sizeof(float));
		//file.write(reinterpret_cast<char*>(&pos[2]), sizeof(float));

		file.write(reinterpret_cast<char*>(pos), sizeof(float) * 3);

		file.close();
	}
}

void FileManager::loadPos(char* filePath)
{
	ifstream file(filePath, ios::in, ios::binary);

	if (file.is_open()) 
	{
		posArr = new float[3];
		file.read(reinterpret_cast<char*>(posArr), sizeof(float) * 3);
		file.close();
	}
}

float* FileManager::getPos()
{
	return posArr;
}
