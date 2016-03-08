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
	MergeSort(a, 0, n-1);
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
void Merge(int *A, int first, int last)
{
	int middle, start, final, j;
	int *mas = new int[100];
	middle = (first + last) / 2; //вычисление среднего элемента
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (j = first; j <= last; j++) //выполнять от начала до конца
	if ((start <= middle) && ((final>last) || (A[start]<A[final])))
	{
		mas[j] = A[start];
		start++;
	}
	else
	{
		mas[j] = A[final];
		final++;
	}
	//возвращение результата в список
	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
};
//рекурсивная процедура сортировки
void MergeSort(int *A, int first, int last)
{
	{
		if (first<last)
		{
			MergeSort(A, first, (first + last) / 2); //сортировка левой части
			MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
			Merge(A, first, last); //слияние двух частей
		}
	}
}
