#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>
#define BUFFSIZE 100
int _tmain(int argc, LPWSTR argv[])
{
	HANDLE hfile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2)
	{
		_tprintf(_T("Usage filename.exe<name of the file>\n"));
		getchar();
		return FALSE;
	}
	hfile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesn't exist (%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("FILE %s opened successfully\n"), argv[1]);

	DWORD nbr;
	DWORD nBytesRead = BUFFSIZE;
	while (1)
	{
		ZeroMemory(buffer, BUFFSIZE);
		BOOL ret = ReadFile(hfile, buffer, BUFFSIZE, &nbr, NULL);
		if (ret == 0)
		{
			_tprintf(_T("Can't read File (%d)\n"), GetLastError());
			getchar();
			return FALSE;
		}
		if (ret && nBytesRead == 0)
		{
			_tprintf(_T("end of file"));
			break;
		}
		_tprintf(_T("%hS"), buffer);
	}
	//tprintf(_T("TEXT from (%s) %S\n"), argv[1], buffer);
	CloseHandle(hfile);

	getchar();
	return TRUE;
}