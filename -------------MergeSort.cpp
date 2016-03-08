#include <iostream>
using namespace std;

void MergeSort(int *A, int f, int l);
void Merge(int *A, int f, int l);
void DisplayArray(int a[], int n);
int* RandomArray(int n);
void Swap(int *a, int *b);

int main()
{
	int n;
	cout << endl << "For the array A n= " << endl;
	cin >> n;
	int*a = RandomArray(n);

	cout << "Source arrays: " << endl;
	DisplayArray(a, n);
	cout << endl;
	MergeSort(a, 0, n - 1);
	DisplayArray(a, n);
	system("pause");
	return 0;
}

int* RandomArray(int n)
{
	int  *a = new int[n];
	for (int* p = a; p < a + n; p++)
		*p = rand() % 200 - 100;
	return a;
}
void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
}
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

