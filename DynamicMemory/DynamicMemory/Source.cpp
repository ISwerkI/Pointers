#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int value, int& n);
int* push_front(int arr[], int value, int& n);
int* insert(int arr[], int value, int& n, int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n,int index);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	int user_num;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� �������: "; cin >> value;
	cout << "����� �������� �� ������ ���������� � ��������?" << endl << "0. push_back" << endl << "1. push_front" << endl << "2. insert" << endl<<"3. pop_front"<<endl<<"4. pop_back"<<endl<<"5. erase"<<endl;
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
		cout << "������� ������ �� �������� ������ ����������� ��������: "; cin >> index;
		arr = insert(arr, value, n, index);
	}
	else if (user_num == 3)
	{
		arr = pop_front(arr, n);
	}
	else if (user_num == 4)
	{
		arr = pop_back(arr, n);
	}
	else if (user_num == 5)
	{
		int index;
		cout << "������� ������ �� �������� ������ ����������� ��������: "; cin >> index;
		arr=erase(arr,n,index);
	}
	else
	{
		cout << "������ ����������� �������";
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
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete arr;
	arr = buffer;
	n--;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete arr;
	arr = buffer;
	n--;
	return arr;
}

int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n-1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete arr;
	arr = buffer;
	n--;
	return arr;
}