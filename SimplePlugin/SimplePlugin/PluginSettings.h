#pragma once
#ifdef SIMPLE_PLUGIN_EXPORTS
#define PLUGIN_API __declspec(dllexport)
#elif SIMPLE_PLUGIN_IMPORTS
#define PLUGIN_API __declspec(dllimport)
#else
#define PLUGIN_API
#endif

