#include<iostream>
using namespace std;
class emp {
	float sal;
public:
	emp()
	{
		sal = 0;
		cout << "default constructor called" << endl;

	}
	emp(float s)
	{
		sal = s;
		cout << "Constrctor with a parameter is called" << endl;
	}
	emp(emp &e)
	{
		sal = e.sal;
		cout << "Copy Constrcutor is called" << endl;

	}
	~emp()
	{
		cout << "Destructor is called" << endl;
	}
	friend void val(emp e);
	friend void ref(emp &e);
};
void val(emp e)
{

	cout << sizeof(e)<<endl;
}
void ref(emp &e)
{
	cout << sizeof(e) << endl;
}
int main()
{
	emp e1, e2(58000), e3(e2);
	val(e2);
	ref(e2);

}

