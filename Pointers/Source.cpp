#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


//#define POINTERS_BASICS
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS

	cout << "Hello Pointers!" << endl;
	int a = 2;
	int* pa = &a;
	cout << a << endl;
	cout << &a << endl; //Взятие адреса переменной а прямо в выводе
	cout << pa << endl; //Вывод на экран адреса переменной а хранящегося в указателе pa
	cout << *pa << endl; //Возврат значения указателя


	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << pb << endl;
#endif
	
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
}