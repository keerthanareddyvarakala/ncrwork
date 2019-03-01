#include <windows.h>
#include <stdio.h>
#include <tchar.h>
DWORD WINAPI Thread_func(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=(%d)\n", i);
		Sleep(1000);
	}
	return 0;
}
void _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD thID1;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	HANDLE hthread1;
	printf("Thread Execution\n");
	hthread1 = CreateThread(NULL, 0, Thread_func, NULL, 0, &thID1);
	if (hthread1 == NULL)
	{
		printf("Unable to create thread , error %d", GetLastError());
		getchar();
		return ;
	}

	if (argc != 2)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return;
	}


	if (!CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi)
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		getchar();
		return;
	}


	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Current process ID - %d\n", GetCurrentProcessId());
	printf("Current Thread Id - %d\n", GetCurrentThreadId());
	printf("ProcessId - %d\n", GetProcessId(pi.hProcess));
	printf("Thread Id - %d\n", GetThreadId(pi.hThread));
	printf("Process Id Of Thread - %d\n", GetProcessIdOfThread(pi.hThread));
	getchar();
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	getchar();
	
}