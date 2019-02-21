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
	for (i = 0; i < n; i++)
	{
		j = i;
		temp = a[j];
		while ((j - 1) != 0 && a[j - 1] > temp)
		{
			a[j] = a[j - 1];
			j--;
		}
		for (i = 0; i <= n - 1; i++)
		{
			j = i - 1;
			temp = a[i];
			while (j >= 0 && a[j] > temp)
			{
				a[j + 1] = a[j];
				j--;
				a[j + 1] = temp;
			}
		}
	}
	cout << "sorted elements" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << "\t";
}