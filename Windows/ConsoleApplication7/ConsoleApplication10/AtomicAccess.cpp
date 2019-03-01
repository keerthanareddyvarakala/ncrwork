#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>

long g_x = 0;
DWORD WINAPI thread_func(LPVOID lparam)
{
	g_x++;
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_x, 1);
	//g_x++;
	return 0;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hthread1, hthread2,hthread3;
	HANDLE arry_hand[3];
	while (1)
	{
		g_x = 0;
		hthread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &thID1);
		if (hthread1 == NULL)
		{
			printf("Unable to create thread , error %d", GetLastError());
			getchar();
			return 1;
		}
		hthread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &thID2);
		if (hthread2 == NULL)
		{
			printf("Unable to create thread , error %d", GetLastError());
			getchar();
			return 1;
		}
		hthread3 = CreateThread(NULL, 0, thread_func, NULL, 0, &thID1);
		if (hthread3 == NULL)
		{
			printf("Unable to create thread , error %d", GetLastError());
			getchar();
			return 1;
		}
		arry_hand[0] = hthread1;
		arry_hand[1] = hthread2;
		arry_hand[2] = hthread3;
		WaitForMultipleObjects(2, arry_hand, TRUE, INFINITE);
		printf("g_x value is %ld\n", g_x);
		if (g_x == 1)
			break;
	}
	printf("waiting for user input before ending process\n");
	CloseHandle(hthread1);
	CloseHandle(hthread2);
	getchar();
	return 0;
}
