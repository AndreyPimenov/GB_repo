#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
int random(int min, int max) {

	int number = min + rand() % (max - min);
	return number;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int** initArray(int** array, const int row, const int col) {
	array = (int**)calloc(sizeof(int*), row);
	for (int i = 0; i < row; ++i) {
		*(array + i) = (int*)calloc(sizeof(int), col);
	}
	return array;
}

void fillArray_int(int** array, const int row, const int col) {

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			*((*(array + i)) + j) = random(1,50); //((i + r) * (j + 1))/10;
		}
	}
}

void printArray_int(int** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("[%4d]", *((*(array + i)) + j));
		}
		printf("\n");
	}
}


int** arr; // for compiling in MVS, it needed to be named in advanced

// Home Task:
/*
#1
Реализовать пузырьковую сортировку двумерного массива
например, массив
1,9,2
5,7,6
4,3,8
должен на выходе стать
1,2,3
4,5,6
7,8,9

#2
Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута
1 - запросить у пользователя 11 чисел и записать их в последовательность П
2 - инвертировать последовательность П
3 - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3)
и если результат вычислений превышает 400 - проинформировать пользователя.

#3
Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С

Результатом выполнения задания должны стать два файла: с кодом на языке С, содержащим функцию main и две функции,
соответствующие сортировке и алгоритму Трабба-Прадо-Кнута, и с изображением в любом популярном формате (jpg, png, gif)
*/

// Bubble_Sorting (my 1st variant):


void bubble2dSort(int** array, const int row, const int col) {
	// It is possible to change 2D Array in 1D Array and sort it and create new 2D array (for static array) 
	// Another way:
	int temp =0; 
	bool flag = false; //equal true if sorting is done

	do{
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				// Bubble sorting in each row:
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col - 1; j++) {

   						if (array[i][j] > array[i][j + 1]) {
							swap(&array[i][j + 1], &array[i][j]);
						}

						
					}
				}

				// Checking the boarder elements - last of the previous row and the first of next row
				for (int i = 0; i < row; i++) {
					if ((i != row - 1) && (array[i][col-1] > array[i + 1][0])) {
						swap(&array[i][col - 1], &array[i + 1][0]);
						flag = false;
					}
					else {
						flag = true;
					}
				}
				
			}
		}

	} while (!flag);

}



int main()
{
	srand(time(NULL));   // Change base for random number generator
	const int row = 5;
	const int col = 9;

	printf("Initial array: \n");
	arr = initArray(arr, row, col);
	fillArray_int(arr, row, col);
	printArray_int(arr, row, col);

	printf("Sorted array: \n");
	bubble2dSort(arr, row, col);
	printArray_int(arr, row, col);

	return 0;
}

