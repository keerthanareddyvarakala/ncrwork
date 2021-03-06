#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#define NOOFPROCS 2
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;
	SECURITY_ATTRIBUTES sa;
	HANDLE hproc, hfile;
	ZeroMemory(&si1, sizeof(si1));
	ZeroMemory(&si2, sizeof(si2));
	si1.cb = sizeof(si1);
	si2.cb = sizeof(si2);
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&pi2, sizeof(pi2));
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	hfile = CreateFile(argv[0], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (argc != 3)
	{
		printf("Usage\n");
		getchar();
		return;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create Process error (%d)\n", GetLastError());
		getchar();
		return;
	}
	printf("Handle of the process:%d\n", pi1.hProcess);
	printf("Process ID of proces:%d\n", pi1.dwProcessId);
	printf("Process thread of process:%d", pi1.dwThreadId);


	CloseHandle(pi1.hThread);
	CloseHandle(pi1.hProcess);
	CloseHandle(hfile);
	getchar();
}