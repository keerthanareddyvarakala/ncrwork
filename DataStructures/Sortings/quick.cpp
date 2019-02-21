#include<iostream>
using namespace std;
void Quicksort(int a[],int low, int high)
{
	int pivot = a[low];
	int i, j;
	int temp;
	i = low + 1;
	j = high;
	if (low < high)
	{
		while (1)
		{
			while (i <= high&&a[i] < pivot)
				i++;
			while (a[j] > pivot)
				j--;
			if (i < j)
			{

				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				break;
		}
		temp = a[low];
		a[low] = a[j];
		a[j] = temp;
		Quicksort(a,low, j - 1);
		Quicksort(a,j + 1, high);
	}
}
int main()
{
	int a[100];
	int i, j, n, temp;
	cout << "enter the no of elements" << endl;
	cin >> n;
	cout << "enter the elements" << endl;
	for (i = 0; i < n; i++)
		cin >> a[i];
	Quicksort(a, 0, n - 1);
	cout << "sorted elements" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << "\t";

}