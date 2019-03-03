#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>

DWORD WINAPI Thread_func(LPVOID lparam)
{
	printf("Child Thread\n");
	return 0;
}
int main()
{
	DWORD thID1;
	HANDLE hthread1;
	hthread1 = CreateThread(NULL, 0, Thread_func, NULL, 0, &thID1);
	if (hthread1 == NULL)
	{
		printf("Unable to create thread , error %d", GetLastError());
		getchar();
		return 1;
	}



	printf("waiting for user input before ending process\n");
	CloseHandle(hthread1);

	getchar();
	return 0;
}
