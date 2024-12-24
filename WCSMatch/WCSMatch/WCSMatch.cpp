// WCSMatch.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <iostream>

#define MAX_PATH 260
#define POOLSIZE 1024

#define POOL_PATH L"C:\\ProgramData\\Microsoft\\WDF\\HardwareIDs.txt"



static int mainp() {
    //const wchar_t* str = L"こんにちは世界界界界界PPPS";
    //const wchar_t* searchStr = L"世界界";

	const wchar_t* str       = L"USB\\VID_04D9&PID_2011&REV_0390\nUSB\\VID_046D&PID_C52B&REV_1211\nUSB\\VID_04D9&PID_2011&REV_0390\nUSB\\VID_0BDA&PID_58B0&REV_0005";
	const wchar_t* searchStr = L"USB\\VID_04D9&PID_2011&REV_0390";

	wchar_t* found = (wchar_t*)wcsstr(str, searchStr);

    if (found) {
        wprintf(L"Found at position: %lu\n", (ULONG) (found - str));
    } else {
        wprintf(L"Not found\n");
    }

    return 0;
}

#if 0

//
// WCSMatch -- Match a wide-character string against a pool of strings
//   The function compares a wide-character string against a pool of WCHAR strings.
// Which includes the speclial character(L'\n', L'\r', L'\0') sepalated by the delimiter.
//
int WCSMatch(PWCHAR Target, PWCHAR Pool) {

	const wchar_t* str = L"こんにちは世界"; const wchar_t* searchStr = L"世界"; wchar_t* found = wcsstr(str, searchStr);


	{
		const wchar_t* str = L"こんにちは世界"; const wchar_t* searchStr = L"世界"; wchar_t* found = wcsstr(str, searchStr); if (found) { wprintf(L"Found at position: %d\n", found - str); }
		else { wprintf(L"Not found\n"); } return 0


	INT i = 1;
	UINT poolSize = wcslen(Pool);
	PWCHAR poolBuffer;

	poolBuffer = (PWCHAR)malloc(MAX_PATH * sizeof(WCHAR));
	if (poolBuffer == NULL) {
		return -1;
	}

	wcsstr()



	PWCHAR q = Pool;
	return 0;
}
#endif

int main()
{
	//WCHAR Target[] = L"USB\\VID_0BDA&PID_58B0&REV_0005";
	WCHAR Target[] = L"USB\\VID_04D9&PID_2011&REV_0390";
	WCHAR pool[POOLSIZE];
	FILE* fp = nullptr;
	INT outs = 0;

	std::cout << "Hello WCSMatch!\n";

	errno_t err;
	err = _wfopen_s(&fp, POOL_PATH, L"r");
	if (err != 0 || fp == nullptr) {
		printf("The file was not opened\n");
		return 1;
	}
	fread(pool, sizeof(WCHAR), POOLSIZE, fp);
	fclose(fp);
	
	//outs = WCSMatch(Target, pool);

	mainp();

	std::cout << "end: " << outs << std::endl;

	return 0;
}

