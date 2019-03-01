#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>
#define BUFFSIZE 100
int _tmain(int argc, LPWSTR argv[])
{
	HANDLE hfile;
	TCHAR buffer[]=TEXT("hey windows");
	if (argc != 2)
	{
		_tprintf(_T("Usage filename.exe<name of the file>\n"));
		getchar();
		return FALSE;
	}

	hfile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesn't exist (%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("FILE %s opened successfully\n"), argv[1]);

	DWORD nbr;
	BOOL ret = WriteFile(hfile, buffer, sizeof(buffer), &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Can't read File (%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	
	CloseHandle(hfile);

	getchar();
	return TRUE;
}