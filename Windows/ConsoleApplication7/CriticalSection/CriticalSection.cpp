#include <windows.h>
#include <stdio.h>
#include <tchar.h>

const int count = 100;
int g_nSum = 0;
CRITICAL_SECTION g_cs;

DWORD WINAPI FirstThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nSum = 0;
	for (int i = 1; i < count; i++)
	{
		g_nSum += i;
	}
	printf("g_nSum1=(%d)\n", g_nSum);
	LeaveCriticalSection(&g_cs);
	return g_nSum;
}
DWORD WINAPI SecondThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nSum = 0;
	for (int i = 1; i < count; i++)
	{
		g_nSum += i;
	}
	printf("g_nSum2=(%d)\n", g_nSum);
	LeaveCriticalSection(&g_cs);
	return g_nSum;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;
	HANDLE arry_hand[2];
	//DWORD lpExitCode1, lpExitCode2;
	InitializeCriticalSectionAndSpinCount(&g_cs,4000);
	hThread1 = CreateThread(NULL, 0, FirstThread, NULL, 0, &thID1);
	if (hThread1 == NULL)
	{
		printf("Unable to create thread , error %d", GetLastError());
		getchar();
		return 1;
	}
	hThread2 = CreateThread(NULL, 0, SecondThread, NULL, 0, &thID2);
	if (hThread2 == NULL)
	{
		printf("Unable to create thread , error %d", GetLastError());
		getchar();
		return 1;
	}
	arry_hand[0] = hThread1;
	arry_hand[1] = hThread2;
	WaitForMultipleObjects(2, arry_hand, TRUE, INFINITE);
	printf("waiting for user input before ending process\n");
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	DeleteCriticalSection(&g_cs);
	getchar();
	return 0;
}


