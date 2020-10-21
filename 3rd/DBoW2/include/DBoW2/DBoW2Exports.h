#pragma once

#ifdef DBOW2_EXPORTS
#define DBOW2_API __declspec(dllexport)
#else
#define DBOW2_API __declspec(dllimport)
#endif