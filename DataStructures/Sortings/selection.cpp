#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int i, j, n, temp;
	cout << "enter the no of elements" << endl;
	cin >> n;
	cout << "enter the elements" << endl;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		int loc = i, j = i + 1;
		while (j <= n - 1)
		{
			if (a[j] < a[loc])
			{
				loc = j;
			}
			j++;
		}
		temp = a[i];
		a[i] = a[loc];
		a[loc] = temp;
	}
	cout << "sorted elements" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << "\t";
}