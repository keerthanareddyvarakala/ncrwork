// ConsoleApplication6.cpp : Defines the entry point for the console application.
//


#include<iostream>
#include<Windows.h>
#include<stdio.h>

using namespace std;

int main()
{
	int q;
	char c = 'A';
	wchar_t p = L'A';
	//wchar_t w;
	//scanf_s("%C", w);
	cout << "Size of char" << sizeof(c) << endl;
	cout << "Size of w_char" << sizeof(p) << endl;
	printf("wchar_t %C\n", p);
	printf("char %c\n", c);
	char s[10] = "hey hi";//ANSI
	wchar_t l[10] = L"hey hello";//WIDE
	printf("wchar_t %S\n", l);
	printf("char %s\n", s);
	BOOL ret = IsTextUnicode(s, strlen(s), NULL);
	if (1 == ret)
		printf("s(ANSI) is a Unicode\n");
	else
		printf(" s(ANSI) not a Unicode\n");

	BOOL ret1 = IsTextUnicode(l, wcslen(l), NULL);
	if (1 == ret1)
		printf("l(WIDE) is a Unicode\n");
	else
		printf("l(WIDE) is not a Unicode\n");

	int size;
	size = MultiByteToWideChar(CP_UTF8,
		0,
		s,
		-1,
		NULL,
		0);
	if (size == 0)
		printf("error is %d", GetLastError());
	else
		printf("Length of s(ANSI) is: %S\n", s);
	CHAR *a = new CHAR[size];
	int i;
	i = WideCharToMultiByte(CP_UTF8,0,l,-1,a,0,NULL,NULL);
	if (i == 0)
		printf("error is %d", GetLastError());
	else
		printf("Length of l(WIDE) is: %S\n", l);




	cin >> q;//to stop the console from shutting down
	return 0;
}

