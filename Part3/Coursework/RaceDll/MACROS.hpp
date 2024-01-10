#pragma once

#ifndef RACEDLL_EXPORTS
#define RACEDLL_EXPORTS
#endif

#ifdef RACEDLL_EXPORTS
#define RACE_API __declspec(dllexport)
#else
#define RACE_API __declspec(dllimport)
#endif