#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<Windows.h>
#define MAXPATH 260
using namespace std;
void DumpEnvString(PTSTR penvBlock[]);

int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvString(env);
	TCHAR envVarString0[] = TEXT("%System Root%");
	TCHAR envVarString1[] = TEXT("%Windir%");
	TCHAR envVarString2[] = TEXT("%User%");
	TCHAR buffer[MAXPATH];

	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString0, buffer, MAXPATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%S\n", buffer);
	ret = ExpandEnvironmentStrings(envVarString1, buffer, MAXPATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%S\n", buffer);
	ret = ExpandEnvironmentStrings(envVarString2, buffer, MAXPATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%S\n", buffer);


}
void DumpEnvString(PTSTR penvBlock[])
{
	int curr = 0;
	PTSTR *pele = (PTSTR *)penvBlock;
	PTSTR pCurrent = NULL;
	while (pele != NULL)
	{
		pCurrent = PTSTR(*pele);
		if (pCurrent == NULL)
			pele = NULL;
		else
		{
			_tprintf(TEXT("[%u]%s\r\n"), curr, pCurrent);
			curr++;
			pele++;
		}
	}
	getchar();

}