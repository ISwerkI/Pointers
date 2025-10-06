#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
template<typename T>void Print(T arr, const int n);
template<typename T>T* push_back(T arr[], T value, int& n);
template<typename T>T* push_front(T arr[], T value, int& n);
template<typename T>T* insert(T arr[], T value, int& n, int index);
template<typename T>T* pop_back(T arr[], int& n);
template <typename T>T* pop_front(T arr[], int& n);
template<typename T>T* erase(T arr[], int& n, int index);

template <typename T>T** Allocate(int rows, int cols);
template<typename T>void Clear(T** arr, int rows);
template<typename T>void Print(T** arr, const int ROWS, const int COLS);
template <typename T>T** push_row_back(T** arr, int& rows, int const cols);
template <typename T>T** push_row_front(T** arr, int ROWS, const int COLS);
template <typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template <typename T>T** insert_row(T** arr, int& rows, const int cols, int index);
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template <typename T>T** erase_row(T** arr, int& rows, const int cols, int index);
template <typename T>void push_col_back(T** arr, const int rows, int& cols);
template <typename T>void push_col_front(T** arr, const int rows, int& cols);
template <typename T>void pop_col_back(T** arr, const int rows, int& cols);
template <typename T>void insert_col(T** arr, const int rows, int& cols, int index);
template <typename T>void erase_col(T** arr, const int rows, int& cols, int index);
void FillRand(int** arr, const int ROWS, const int COLS);
void FillRand(double** arr, const int ROWS, const int COLS);
void FillRand(char** arr, const int ROWS, const int COLS);

#define tab "\t"
//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2
#define DATA_TYPE int

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n = 5;
	int user_num;
	cout << "Введите размер массива: "; cin >> n;
	DATA_TYPE* arr = new DATA_TYPE[n];
	FillRand(arr, n);
	Print(arr, n);
	DATA_TYPE value;
	cout << "Введите элемент: "; cin >> value;
	cout << "Какие действия вы хотите провернуть с массивом?" << endl << "0. push_back" << endl << "1. push_front" << endl << "2. insert" << endl << "3. pop_front" << endl << "4. pop_back" << endl << "5. erase" << endl;
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
		cout << "Введите индекс по которому хотите расположить значение: "; cin >> index;
		arr = erase(arr, n, index);
	}
	else
	{
		cout << "Введен неизвестный элемент";
	}
	Print(arr, n);
	delete arr;
#endif
#ifdef DYNAMIC_MEMORY2
	int cols = 4;
	int rows = 5;

	DATA_TYPE** arr = Allocate<DATA_TYPE>(rows,cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	erase_col(arr,rows, cols, 3);
	Print(arr, rows, cols);
	Clear(arr, rows);
#endif
}
template<typename T>T** Allocate(const int rows,const int cols)
{
	T** arr = new T * [rows];
	for (int i = 0; i < rows; i++) arr[i] = new T[cols];
	return arr;
}
template<typename T>void Clear(T** arr, int rows)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;

}
template<typename T>void Print(T** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++) cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << endl << endl;
}
template<typename T>T* push_back(T arr[], T value, int& n)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete arr;
	arr = buffer;
	arr[n++] = value;
	return arr;
}
template<typename T>T* push_front(T arr[], T value, int& n)
{
	T* buffer = new T[n + 1];
	for (int i = 1; i <= n; i++) buffer[i] = arr[i - 1];
	delete arr;
	buffer[0] = value;
	arr = buffer;
	n++;
	return arr;
}
template<typename T>T* insert(T arr[], T value, int& n, int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	buffer[index] = value;
	for (int i = index + 1; i <= n; i++) buffer[i] = arr[i - 1];
	delete arr;
	arr = buffer;
	n++;
	return arr;
}
template <typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++) buffer[i] = arr[i + 1];
	delete arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++) buffer[i] = arr[i];
	delete arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T* erase(T arr[], int& n, int index)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < n - 1; i++)buffer[i] = arr[i + 1];
	delete arr;
	arr = buffer;
	n--;
	return arr;
}
template <typename T>T** push_row_back(T** arr, int& rows, int const cols)
{
	return  push_back(arr, new T[cols]{}, rows);
}
void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++) for (int j = 0; j < COLS; j++) arr[i][j] = rand() % 100;
}
void FillRand(double** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++) for (int j = 0; j < COLS; j++) arr[i][j] = (rand() % 10000)/100;
}
void FillRand(char** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)for (int j = 0; j < COLS; j++)arr[i][j] = rand();
}
template <typename T>T** push_row_front(T** arr, int ROWS, const int COLS)
{
	return push_front(arr, new T[COLS]{}, ROWS);
}
template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	return pop_back(arr, rows);
}
template <typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	return insert(arr, new T[cols]{}, rows, index);
}
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	delete[] arr[0];
	return pop_front(arr, rows);

}
template <typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
	delete[] arr[index];
	return erase(arr, rows,index);
}
template <typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], T(), cols);
		cols--;
	}
	++cols;
}
template <typename T>void push_col_front(T** arr, const int rows, int& cols) 
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], T(), cols);
		cols--;
	}
	++cols;
}
template <typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols--;
	}
}
template <typename T>void insert_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], T(), cols,index);
		cols--;
	}
	++cols;
}
template <typename T>void erase_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = erase(arr[i], cols, index);
	}
}
template<typename T>void Print(T arr, const int n)
{
	for (int i = 0; i < n; i++) cout << arr[i] << tab;
	cout << endl;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++) arr[i] = rand() % (maxRand - minRand) + minRand;
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++) arr[i] = rand();
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++) arr[i] = (rand() % (maxRand - minRand) + minRand) / 100;
}