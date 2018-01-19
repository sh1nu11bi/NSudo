// NSudoC.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "resource.h"

#include <Windows.h>

#include "m2base.h"

int main()
{
	HMODULE Module = GetModuleHandleW(nullptr);
	
	HRSRC Resource = FindResourceExW(
		Module,
		L"String", 
		MAKEINTRESOURCEW(IDR_CommandLineHelpPage), 
		MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL));

	HGLOBAL Global = LoadResource(Module, Resource);

	const char* Memory = (const char*)LockResource(Global);
	Memory = Memory;

	auto string = m2_base_utf8_to_utf16(Memory);

	wprintf(L"%s", string.c_str());
	
	return 0;
}

