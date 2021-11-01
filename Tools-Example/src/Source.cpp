#include <iostream>

#include <DTools.h>

using namespace DTools;

int main()
{
	DKTools::Init();

	DK_CORE_INFO("This is Dark-Tools Example");

	return std::cin.get();
}