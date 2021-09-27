//HW7:
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

/*
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

*/

// PS Udesul link:
// https://stackoverflow.com/questions/4134323/c-how-to-delete-a-structure

// HW8:
// Cделать решение на поле 4х4 или 5х5 или на динамическом поле, размер которого ввел пользователь.
// Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3 - 5.

#include <iostream>
#include <string>

//using namespace std;

enum gameSymbols { empty, X, O,};
bool orderFlg = 1; // 1 - 1st player "X"; 0 - 2nd player "O" 
int orderStep; // th

char printSymbol(gameSymbols cell) {
	// symbol printing:
	if (cell == gameSymbols::empty)
		return '-';
	if (cell == gameSymbols::X)
		return 'X';
	if (cell == gameSymbols::O)
		return '0';
}

gameSymbols** fieldGeneration(int Rows, int Colomns) {
	// initialization of the field array:
	gameSymbols** gameArray = new gameSymbols * [Rows];

	for (int r = 0; r < Rows; r++) {
		gameArray[r] = new gameSymbols[Colomns]();
		for (int c = 0; c < Colomns; c++) {
			gameArray[r][c] = gameSymbols::empty;
			//std::cout << " r = " << r << " c= " << c << " this element: " << printSimbol(gameArray[r][c]) << std::endl;
		}
	}

	return gameArray;
}

void gameFieldUpdate(gameSymbols** array, int Rows, int Colomns) {
	std::cout << "This is relevant game field: " << std::endl;
	for (int r = 0; r < Rows; r++) {
		
		array[r] = new gameSymbols[Colomns]();
		for (int c = 0; c < Colomns; c++) {
			std::cout << printSymbol(array[r][c]) << "  ";
		}
		std::cout << std::endl;
	}
}

bool gameSymbolChange(gameSymbols** array, int Rows, int Colomns, bool player) {
	int x = 0;
	int y = 0;

	std::cout << "Enter the x coordinate:" << std::endl;
	std::cin >> x;

	std::cout << "Enter the y coordinate:" << std::endl;
	std::cin >> y;

	if (array[x][y] == gameSymbols::empty) {
		if (player == 1) {
			array[x][y] = gameSymbols::X;
		}
		if (player == 2) {
			array[x][y] = gameSymbols::O;
		}
		return true;
	}
	else {
		std::cout << "Same player try again" << std::endl;
	}return false;
}

bool playerMakeStep(gameSymbols** array, int Rows, int Colomns, bool player) {
	bool result; // true = step was succesfully finished; false = same player needs to make another step 
	if (player == 1) {
		std::cout << "1st player make step: " << std::endl;
		result = gameSymbolChange(array, Rows, Colomns, player);
		if (result) {
			gameFieldUpdate(array, Rows, Colomns);
			player = !player;
		}
		else { player = player; }
		
	}

	else if (player == 0) {
		std::cout << "2nd player make step: " << std::endl;

		if (gameSymbolChange(array, Rows, Colomns, player)) {
			gameFieldUpdate(array, Rows, Colomns);
			player = !player;
		}
		else { player = player; }
	}
	return player;
}


// free space:
void deleteGameField(gameSymbols** data, int Rows)
{
	for (int r = 0; r < Rows; r++) delete[] data[r];
	delete[] data;
}


int main() {

	// 1st Block - Initialisation of the field & victory vector sizes:
	int fieldSize;
	std::cout << "Enter the size of square field: " << std::endl;
	std::cin >> fieldSize;
	fieldSize = (static_cast<int>(fieldSize) == fieldSize) ? fieldSize : 3; // filedSize must be integer

	int vectorSize;
	std::cout << "Enter the size of the sequence enought for victory " << std::endl;
	std::cin >> vectorSize;
	vectorSize = ((static_cast<int>(vectorSize) == vectorSize) & (static_cast<int>(vectorSize) < fieldSize)) ? vectorSize : 3;
	 
    gameSymbols ** gameField =  fieldGeneration(fieldSize, fieldSize);

	// 2nd Block - Game:
	while (orderStep < fieldSize * fieldSize) {

		orderFlg = playerMakeStep(gameField, fieldSize, fieldSize, orderFlg);
		
		orderStep++; 

	}



	// 3rd Block - empty space after the working process:
	deleteGameField(gameField, fieldSize); 
	gameField = nullptr;
	return 0; 
}


// PS:
// 1. resizing the array: 
// https://stackoverflow.com/questions/42238712/change-array-size-c#:~:text=To%20resize%20an%20array%20you,%5Bold_size%5D%3B%20%2F%2F...
// 2. array intialization through link / function:
// https://coderoad.ru/31230610/C-%D0%B8%D0%BD%D0%B8%D1%86%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2%D0%B0-%D0%BF%D0%BE-%D1%81%D1%81%D1%8B%D0%BB%D0%BA%D0%B5-%D1%87%D0%B5%D1%80%D0%B5%D0%B7-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8E
// 3. проверка на целочисленный тип данных:
// https://coderoad.ru/784563/C-%D0%BF%D1%80%D0%BE%D0%B2%D0%B5%D1%80%D0%B8%D1%82%D1%8C-%D1%8F%D0%B2%D0%BB%D1%8F%D0%B5%D1%82%D1%81%D1%8F-%D0%BB%D0%B8-%D1%87%D0%B8%D1%81%D0%BB%D0%BE-%D0%B8%D0%BD%D1%82-%D1%84%D0%BB%D0%BE%D0%B0%D1%82

	
