#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int value, int& n);
int* push_front(int arr[], int value, int& n);
int* insert(int arr[], int value, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	int user_num;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите элемент: "; cin >> value;
	cout << "Какие действия вы хотите провернуть с массивом?" << endl << "0. push_back" << endl << "1. push_front" << endl << "2. insert" << endl;
	cin >> user_num;
	if (user_num == 0)
	{
		arr = push_back(arr, value, n);
	}
	else if (user_num == 1)
	{
		arr = push_front(arr, value, n);
	}
	else if (user_num == 2)
	{
		int index;
		cout << "Введите индекс по которому хотите расположить значение: "; cin >> index;
		arr = insert(arr, value, n,index);
	}
	else
	{
		cout << "Введен неизвестный элемент";
	}
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

int* push_front(int arr[], int value, int& n)
{   
	int* buffer = new int[n+1];
	for (int i = 1; i <=n; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete arr;
	buffer[0] = value;
	arr = buffer;
	n++;
	return arr;
}

int* insert(int arr[], int value, int& n,int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	for (int i = index + 1; i <= n; i++)
	{
		buffer[i] = arr[i-1];
	}
	delete arr;
	arr = buffer;
	n++;
	return arr;
}