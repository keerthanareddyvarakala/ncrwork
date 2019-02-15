#include<iostream>
using namespace std;

void swap_value(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "after swapping" << a << b << endl;

}
void swap_refer(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	cout << "after swapping" << *a<<*b << endl;


}
void swap(int &i, int &j)
{
	i = i + j;
	j = i - j;
	i = i - j;
	cout << "after swapping" << i << j << endl;
}

int main()
{
	int i, j;
	int &a = i;
	int &b = j;
	cout << "enter values" << endl;
	cin >> i >> j;
	swap_value(i, j);
	swap_refer(&i, &j);
	swap(a, b);

	

}