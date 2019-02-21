#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int i, j, n, flag;
	cout << "enter the no of elements" << endl;
	cin >> n;
	cout << "enter the elements" << endl;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	cout << "sorted elements" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << "\t";
	return 0;
}