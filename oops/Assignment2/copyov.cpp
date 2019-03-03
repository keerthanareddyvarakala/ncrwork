#include <iostream>
#include <string>
using namespace std;
class Copy
{
	char* stored;
public:

	Copy()
	{
		stored = NULL;
	}
	Copy(char *s)
	{
		stored = s;
	}
	Copy(const char *str)
	{
		stored = new char[strlen(str) + 1];
		strcpy(stored, str);

	}

	void display()
	{
		cout << stored << endl;;
	}
	~Copy()
	{
		delete[] stored;
	}
};
int main()
{
	Copy c1, c2("CBIT"), c3(c2);

	c2.display();
	c3.display();
	return 0;

}