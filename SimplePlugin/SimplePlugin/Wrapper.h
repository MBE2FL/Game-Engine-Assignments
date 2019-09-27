#pragma once

#include "PluginSettings.h"
#include "SimpleClass.h"
#include "FileManager.h"

#ifdef __cplusplus
extern "C"
{
#endif

	PLUGIN_API void savePos(char* filePath, float* pos);
	PLUGIN_API void loadPos(char* filePath);
	PLUGIN_API float* getPos();


#ifdef __cplusplus
}
#endif