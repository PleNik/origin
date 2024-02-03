#pragma once

#include<iostream>

#ifdef LEAVINGLIBRARYDYNAMIC_EXPORTS
#define  LEAVINGLIBRARY_API __declspec(dllexport)
#else
#define LEAVINGLIBRARY_API __declspec(dllimport)
#endif // LEAVINGLIBRARYDYNAMIC_EXPORTS

namespace DynamicLeaving {

	class Leaver {
	public:
		LEAVINGLIBRARY_API const std::string leave(const std::string& name);
	};
}