#include <stdio.h>
#include <iostream>
using namespace std;
int sum(int a, int b)
{
return a + b;
}
int maxx(int a, int b)
{
	if (a > b)
	{
		return(a);
	}
	else return(b);
}
int mul(int a, int b)
{
return a * b;
}
int inv(int a)
{
	return a =-a;
}
void SortUbv(int* arr, int len) //сортировка по возрастанию массива
{
	int x = 0; // Доп. переменная для перестановки
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j < len - i; j++)  // Цикл не доходит до конца, т.к. там элементы уже 
		{                                    // стоят на своих местах
			if (arr[j - 1] < arr[j])
			{
				x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
}
void SortVozr(int* arr, int len) //сортировка по возрастанию массива
{
	int x = 0; // Доп. переменная для перестановки
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j < len - i; j++)  // Цикл не доходит до конца, т.к. там элементы уже 
		{                                    // стоят на своих местах
			if (arr[j - 1] > arr[j])
			{
				x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
}

void fold(int* arr, unsigned size, int (*fun)(int,int), int* acc) 
{
	unsigned i = 1;
* acc = fun(arr[i-1], arr[i]);
 for (i = 2; i < size; i++)
 {
	*acc = fun(*acc, arr[i]);
 }
}
void random_arr(int* arr, int len) // заполнение массива случайными числами
{
	srand(time(0)); //инициализация генератора случайных чисел
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 11 - 5; //заполнение числами в промежутке [-5;5]
	}
}
void map(int* arr, unsigned size, int (*fun)(int)) {
	unsigned i;
	for (i = 0; i < size; i++) {
		arr[i] = fun(arr[i]);
		
	}
}
void Print(int* arr, int len) //печать массива длины len
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
 void main() {
 setlocale(LC_ALL, "rus");
 int a[10] = {};
 random_arr(a, 10);
 cout << "Сгенерированный случайный массив: ";
 Print(a, 10);
int result;
fold(a, 10, maxx, &result);
cout << "\nМаксимальный элемент = " << result;
fold(a, 10, mul, &result);
cout << "\nПроизведение элементов = " << result;
 fold(a, 10, sum, &result);

cout << "\nСумма его элементов = " <<result<<endl;
if (result == a[0])
{
	map(a, 10, *inv);
	cout << "CУММА = 1 эл. --> МАССИВ БЫЛ ИЗМЕНЕН!"<<endl;
	cout << "Новый массив: "; 
	Print(a, 10);
}
else if (result > a[0])
{
	SortVozr(a, 10);
	cout << "CУММА > 1 эл. --> МАССИВ БЫЛ ИЗМЕНЕН!" << endl;
	cout << "Новый массив: ";
	Print(a, 10);
}
else
{
	SortUbv(a, 10);
	cout << "CУММА < 1 эл. --> МАССИВ БЫЛ ИЗМЕНЕН!" << endl;
	cout << "Новый массив: ";
	Print(a, 10);
}

 

}