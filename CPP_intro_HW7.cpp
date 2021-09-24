/*
1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) 
во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. 
Вызывайте эти 3-и функции из main для работы с массивом.

2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) 
до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».

3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. 
Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). 
Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.

4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.

5. * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).
*/

// **************************** mylib.h:**************************************************************

#pragma once

// task 1:

void arrayInitialization(float array[], const int);

void arrayPrinting(float array[], const int);

void posNegCounting(float array[], const int);



// task 3:

void arrayBubbleSort(float array[], const int);

// task5:
namespace MyLib {
	void MyLib_arrayInitialization(float array[], const int size);

	void MyLib_arrayPrinting(float array[], const int size);

	void MyLib_posNegCounting(float array[], const int size);

}

// ***************************************************************************************************
// **************************** mylib.cpp:************************************************************
#include <iostream>


// task 1:
void arrayInitialization(float array[], const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Please enter the " << i << " element of the array : "; 
		std::cin >> array[i];
	}
}

void arrayPrinting(float array[], const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void posNegCounting(float array[], const int size) {
	int posNumbers = 0;
	int negNumbers = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] < 0) {
			negNumbers++;
		}
		else {
			posNumbers++;
		}
	}
	std::cout << "Positive numbers = " << posNumbers << std::endl;
	std::cout << "Negative numbers = " << negNumbers << std::endl;
}

// task 3: attemps solve with functions:
void swapInt(float a, float b) {
	/*Чтобы реалищовать через функцию нудно было передавать по ссылкам чтобы менять оригиналы, а не копии*/
	std::cout << a << " & " << b << std::endl;
	a = a + b; // a1 = a + b
	b = a - b; // b1 = a1 - b = (a + b) - b = a >>> inside b we will have a
	a = a - b; // a2 = a1 - b1 = (a + b) - b1 = a + b - a = b >>> inside a we will have b
	std::cout << a << " & " << b << std::endl;

	
}

void swapIntPointers(float* pa, float* pb) {
	*pa = *pb + *pa;
	*pb = *pa - *pb;
	*pa = *pa - *pb;
}


// task5:
namespace MyLib {
	void MyLib_arrayInitialization(float array[], const int size) {
		for (int i = 0; i < size; i++) {
			std::cout << "Please enter the " << i << " element of the array : ";
			std::cin >> array[i];
		}
	}

	void MyLib_arrayPrinting(float array[], const int size) {
		for (int i = 0; i < size; i++) {
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}

	void MyLib_posNegCounting(float array[], const int size) {
		int posNumbers = 0;
		int negNumbers = 0;
		for (int i = 0; i < size; i++) {
			if (array[i] < 0) {
				negNumbers++;
			}
			else {
				posNumbers++;
			}
		}
		std::cout << "Positive numbers = " << posNumbers << std::endl;
		std::cout << "Negative numbers = " << negNumbers << std::endl;
	}

}

// ***************************************************************************************************
// **************************** mylib.h:**************************************************************
/*
1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h)
во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), 
печати его на экран и подсчета количества отрицательных и положительных элементов.
Вызывайте эти 3-и функции из main для работы с массивом.

2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры)
в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, 
вывести на экран «true» или «false».

3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define.
Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком).
Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.

4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. 
Сохраните эту структуру в текстовый файл.

5. * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).
*/

#include <iostream>
#include <fstream>
#include <string>

#include "mylib.h"

using namespace std;

// task 2:
#define PRINT_STR(str)  std::cout << str << endl;
#define LESSTHAN(n1, n2) ( n1 < n2 )

#define ARSIZE 6 
#define SwapINT(a,b) \
int temp = b; b = a; a = temp; \

void arrayBubbleSort(float array[], const int size) {
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			if (array[j] > array[j + 1])
			{
				SwapINT(array[j], array[j + 1]);
			}
	}
}

int main() {
	// task 1
	{
		const int size = 5;
		float arrTask1[size] = {};
		arrayInitialization(arrTask1, size);
		arrayPrinting(arrTask1, size);
		posNegCounting(arrTask1, size);
	}

	// task 2
	{
		int n1 = 0;
		int n2 = 0;
		std::cout << "Enter the fist number: " << std::endl;
		std::cin >> n1;
		std::cout << "Enter the fist number: " << std::endl;
		std::cin >> n2;

		//PRINT_STR(LESSTHAN(n1, n2));

		if (LESSTHAN(n1, n2) == 1) {
			PRINT_STR("true");
		}
		else {
			PRINT_STR("false");
		}
	}


	// task 3
	
	{
		float arrTask3[ARSIZE] = {};
		arrayInitialization(arrTask3, ARSIZE);
		arrayPrinting(arrTask3, ARSIZE);

		arrayBubbleSort(arrTask3, ARSIZE);
		arrayPrinting(arrTask3, ARSIZE);
	}
	


	// task 4
	{
		//Объявить структуру Сотрудник с различными полями.
		//Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
        #pragma pack(push, 1)
		struct Employee {
			string name; 
			string position;
			float salary;
			int id;
		};
        #pragma pack(pop)

		//Выделите динамически переменную этого типа.
		Employee* e1 = new Employee;

		//Инициализируйте ее.
		e1->name = "Bob";
		e1->position = "Head of Sales";
		e1->salary = 1221.45;
		e1->id = 123345;

		//Выведите ее на экран и ее размер с помощью sizeof.
		std::cout << e1->name << endl;
		std::cout << e1->position << endl;
		std::cout << e1->salary << endl;
		std::cout << e1->id << endl;

		std::cout << sizeof(Employee) << endl;

		//Сохраните эту структуру в текстовый файл.
		// creating the file:
		ofstream file("struct.txt");

		// openning the file:
		if (!file) {
			std::cout << "Some problems to writing in file" << std::endl;
		}

		// writing the string to the file
		file << e1->name << endl;
		file << e1->position << endl;
		file << e1->salary << endl;
		file << e1->id << endl;

		//*Удалить структуру:
		delete e1;
	}

	// task 5
	
	{	
		
		const int size = 5;
		float arrTask5[size] = {};
		MyLib::MyLib_arrayInitialization(arrTask5, size);
		MyLib::MyLib_arrayPrinting(arrTask5, size);
		MyLib::MyLib_posNegCounting(arrTask5, size);

	}
	

	return 0; 
}

// PS Udesul link:
// https://stackoverflow.com/questions/4134323/c-how-to-delete-a-structure
// ***************************************************************************************************
