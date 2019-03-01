#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>

DWORD WINAPI Thread_func(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=(%d)\n", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hthread1, hthread2;
	HANDLE arry_hand[2];
	hthread1 = CreateThread(NULL, 0, Thread_func, NULL, 0, &thID1);
	if (hthread1 == NULL)
	{
		printf("Unable to create thread , error %d", GetLastError());
		getchar();
		return 1;
	}
	hthread2 = CreateThread(NULL, 0, Thread_func, NULL, 0, &thID2);
	if (hthread2 == NULL)
	{
		printf("Unable to create thread , error %d", GetLastError());
		getchar();
		return 1;
	}
	arry_hand[0] = hthread1;
	arry_hand[1] = hthread2;
	WaitForMultipleObjects(2, arry_hand, TRUE, INFINITE);
	printf("waiting for user input before ending process\n");
	CloseHandle(hthread1);
	CloseHandle(hthread2);
	getchar();
	return 0;
}
