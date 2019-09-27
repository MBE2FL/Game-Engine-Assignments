#include "Wrapper.h"

FileManager fm;


PLUGIN_API void savePos(char* filePath, float* pos)
{
	return fm.savePos(filePath, pos);
}

PLUGIN_API void loadPos(char* filePath)
{
	return fm.loadPos(filePath);
}

PLUGIN_API float* getPos()
{
	return fm.getPos();
}
