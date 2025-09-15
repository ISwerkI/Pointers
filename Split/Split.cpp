#include <iostream>
using namespace std;

void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	Print(arr, n);
	int even_counter = 0;
	int odd_counter = 0;
	for (int i = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? even_counter : odd_counter)++;
	}
	int* even = new int[even_counter];
	int* odd = new int[odd_counter];
	even_counter = 0;
	odd_counter = 0;
	for (int i = 0; i < n; i++)
	{
		(arr[i] % 2 == 0?even[even_counter++]:odd[odd_counter++]) = arr[i];
	}
	Print(even, even_counter);
	Print(odd, odd_counter);
	delete even;
	delete odd;

}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl<<endl; 
}


