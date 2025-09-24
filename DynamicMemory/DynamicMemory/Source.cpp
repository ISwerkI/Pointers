#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void Print(int** arr, const int ROWS, const int COLS);
int* push_back(int arr[], int value, int& n);
int* push_front(int arr[], int value, int& n);
int* insert(int arr[], int value, int& n, int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);


int** Allocate(int rows, int cols);
void Clear(int** arr, int rows);
int** push_row_back(int** arr, int& rows, int const cols);
void FillRand(int** arr, const int ROWS, const int COLS);
int** push_row_front(int** arr,int ROWS, const int COLS);
int** pop_row_back(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int index);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);
void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int index);
void erase_col(int** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2


void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n = 5;
	int user_num;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
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
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);
	erase_col(arr, rows, cols, 1);
	Print(arr, rows, cols);
	Clear(arr, rows);

#endif
}

int** Allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void Clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand-minRand) + minRand;
	}
}
void Print(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl << endl;
}

int* push_back(int arr[], int value, int& n)
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
	int* buffer = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete arr;
	buffer[0] = value;
	arr = buffer;
	n++;
	return arr;
}

int* insert(int arr[], int value, int& n, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	for (int i = index + 1; i <= n; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete arr;
	arr = buffer;
	n++;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete arr;
	arr = buffer;
	n--;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
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
	for (int i = index; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete arr;
	arr = buffer;
	n--;
	return arr;
}


int** push_row_back(int** arr, int& rows, int const cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
int** push_row_front(int** arr,int ROWS, const int COLS)
{
	int** buffer = new int* [ROWS + 1];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete arr;
	buffer[0] = new int[COLS] {};
	ROWS++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows];
	delete arr;
	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [++rows];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new int [cols] {};
	for (int i = index + 1; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete arr;
	return buffer;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows-1];
	for (int i = 1; i < rows; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr[0];
	delete[] arr;
	rows--;
	return buffer;
		
}

int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index+1; i < rows; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr[index];
	delete[] arr;
	rows--;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	++cols;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = new int[cols];
		buffer[cols-1] = 0;
		arr[i] = buffer;
	}
}

void push_col_front(int** arr, const int rows, int& cols)
{
	++cols;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = new int[cols];
		buffer[0] = 0;
		arr[i] = buffer;
	}
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	--cols;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = new int[cols];
		arr[i] = buffer;
	}
}

void pop_col_front(int** arr, const int rows, int& cols)
{
	--cols;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = new int[cols];
		arr[i] = buffer;
	}
}

void insert_col(int** arr, const int rows, int& cols, int index)
{
	++cols;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		buffer[index] = 0;
		for (int j = index+1; j < cols; j++)
		{
			buffer[j] = arr[i][j-1];
		}
		delete[] arr[i];
		arr[i] = new int[cols];
		arr[i] = buffer;
	}
}

void erase_col(int** arr, const int rows, int& cols, int index)
{
	--cols;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index+1; j < cols+1; j++)
		{
			buffer[j-1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = new int[cols];
		arr[i] = buffer;
	}
}