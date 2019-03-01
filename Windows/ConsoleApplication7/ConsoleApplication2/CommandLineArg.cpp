#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>
using namespace std;

int _tmain(int argc,TCHAR *argv[])
{
	LPWSTR *SLArglist;
	int nargs=argc;
	int i;
	SLArglist = CommandLineToArgvW(GetCommandLineW(),&nargs);
	if (NULL == SLArglist)
	{
		wprintf(L"error\n");
		return 0;
	}
	else
	{
		for (i = 0; i < nargs; i++)
			printf("%d:%lS\n",i,argv[i]);
	}
	getchar();


}