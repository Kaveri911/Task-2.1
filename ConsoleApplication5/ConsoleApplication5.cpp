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

 void main() {
 setlocale(LC_ALL, "rus");
 int a[10] = {};
 random_arr(a, 10);
 cout << "Сгенерированный случайный массив: ";
 for (int i = 0; i < 10; i++)
 {
	 cout << a[i] << " ";
 }
	 int result;
 fold(a, 10, sum, &result);
cout << "\nСумма его элементов = " <<result;
 fold(a, 10, maxx, &result);
 cout << "\nМаксимальный элемент = " << result;
 fold(a, 10, mul, &result);
 cout << "\nПроизведение элементов = " << result;
 

}