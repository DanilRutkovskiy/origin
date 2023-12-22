#pragma once
#include <string>
#ifndef LEAVER_EXPORTS
#define LEAVER_EXPORTS
#endif
#ifdef LEAVER_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif
namespace Leaver {
	class LEAVER_API Leaver {
	public:
		void leave(const std::string& name);
	};
}