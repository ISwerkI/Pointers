#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int value, int& n);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "¬ведите элемент: "; cin >> value;
	arr = push_back(arr, value, n);
	Print(arr, n);
	delete arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
	cout << endl;
}

int* push_back (int arr[], int value, int& n)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete arr;
	arr = buffer;
	arr[n++] = value;
	return arr;
}
