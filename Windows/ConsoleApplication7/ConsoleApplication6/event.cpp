#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>
int main()
{
	HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("namedevent"));
	getchar();
	return 1;

}