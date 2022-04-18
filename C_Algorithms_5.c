#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>

int random(int min, int max) {
	int number = min + rand() % (max - min);
	return number;
}

void swapInt(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// for 1D arrays:
int* init1DArray(int* array, const int sizeArr) {
	array = (int*)calloc(sizeArr-1, sizeof(int*));
	//for (int i = 0; i < sizeArr; ++i) {
	//	*array = calloc(sizeArr, sizeof(int*));
	//}
	return array;
}

void fill1DArray_int(int* array, const int sizeArr) {
	for (int i = 0; i < sizeArr; ++i) {
		array[i] = random(1, 50);
	}
}

void print1DArray_int(int* array, const int sizeArr) {
	for (int i = 0; i < sizeArr; ++i) {
		printf("[%4d]", array[i] );
	}
	printf("\n");
}

// for 2D arrays:
int** init2DArray(int** array, const int row, const int col) {
	array = (int**)calloc(sizeof(int*), row);
	for (int i = 0; i < row; ++i) {
		*(array + i) = (int*)calloc(sizeof(int), col);
	}
	return array;
}

void fill2DArray_int(int** array, const int row, const int col) {

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			*((*(array + i)) + j) = random(1,50); 
		}
	}
}

void print2DArray_int(int** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("[%4d]", *((*(array + i)) + j));
		}
		printf("\n");
	}
}

void bubble2DSort(int** array, const int row, const int col) {
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
							swapInt(&array[i][j + 1], &array[i][j]);
						}
					}
				}

				// Checking the boarder elements - last of the previous row and the first of next row
				for (int i = 0; i < row; i++) {
					if ((i != row - 1) && (array[i][col-1] > array[i + 1][0])) {
						swapInt(&array[i][col - 1], &array[i + 1][0]);
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

int** arr2D; // we have to initialise this variable here, to compiling code in MVS-2019
int* arr1D;

// Class work:

void quickSortHoare(int* arr, int first, int last) {
	int i = first;
	int j = last;

	// Choosing the support element
	int x = arr[(first + last) / 2];

	// Swapping elements around support one to make group less than support and big then support:
	do {
		// Hoar separation:
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;
		
		if (i <= j) {
			swapInt(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	// Recursion 
	if (i < last) { quickSortHoare(arr, i, last); };
	if (first < j) { quickSortHoare(arr, first, j); };
}

void quickSortLomuto(int* arr, int first, int last ) {

	if (first < last) {
		int x = arr[last]; // x - support element
		int i = first;
		int j;

		for (j = first; j <= last-1; j++) {
			if (arr[j] <= x) {
				swapInt(&arr[i], &arr[j]);
				i++;
			}
		}
		swapInt(&arr[i], &arr[last]);
		quickSortLomuto(arr, first, i - 1);
		quickSortLomuto(arr, i + 1, last);
	}

}

void thickSplit(int* arr, int l, int r){
	int x = arr[r];
	if (r <= l) return;

	int i = l;
	int j = r - 1;
	int p = l - 1;
	int q = r;

	while (i <= j) {
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i >= j) break;
		swapInt(&arr[i], &arr[j]);

		if (arr[i] == x) {
			p++;
			swapInt(&arr[p], &arr[i]);
			i++;
		}

		if (arr[j] == x) {
			swapInt(&arr[--q], &arr[j--]);
		}
	}

	swapInt(&arr[i], &arr[r]);
	j = i - 1;
	i++;

	for (int k = l; k <= p; ++k, --j) {
		swapInt(&arr[k], &arr[i]);
	}

	for (int k = r - 1; k >= q; ++k, ++i) {
		swapInt(&arr[k], &arr[i]);
	}

	thickSplit(arr, l, j);
	thickSplit(arr, i, r);


}

// Home work:
/*
1) Описать в коде улучшенный алгоритм быстрой сортировки.

2) Сортировать в массиве целых положительных чисел только чётные числа, 
нечётные оставив на своих местах при помощи алгоритма блочной сортировки, 
то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]

Результатом работы должен стать один файл с кодом на языке С, 
содержащий функцию main и функции, необходимые для реализации сортировок
*/


void improvedSorting(int* arr, int first, int last) {
	// Суть метода в том, чтобы выбрать опорный элемент 
	// наиболее близкий к медианному значению. далее классика:
	int i = first;
	int j = last;
	int x;
	// Choosing the support element
	int x1 = arr[(first + last) / 2]; // middle index
	int x2 = arr[(((first + last) / 2) + last) / 2]; // b/n middle and last index
	int x0 = arr[(((first + last) / 2) + first) / 2]; // b/n first and middle index

	int delta = (x1 + x2 + x0) / 3;
	if ((abs(x1 - delta) <= abs(x0 - delta)) && (abs(x1 - delta) <= abs(x2 - delta))) { x = x1; }
	else if ((abs(x0 - delta) <= abs(x1 - delta)) && (abs(x0 - delta) <= abs(x2 - delta))) { x = x0; }
	else { x = x2; }

	// Swapping elements around support one to make group less than support and big then support:
	do {
		// Hoar separation:
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j) {
			swapInt(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	// Recursion 
	if (i < last) { quickSortHoare(arr, i, last); };
	if (first < j) { quickSortHoare(arr, first, j); };




}

void bucketSorting(int* arr, int len) {
	const int bucket_len = len; // max elements in each buckets
	const int b = 10; // кол-во корзин

	int buckets[b][bucket_len];
	//int buckets[b][bucket_len];

	for (int i = 0; i < b; ++i) {
		buckets[i][bucket_len] = 0; 
	}

	for (int digit = 1; digit < 100000000000; digit*=10){
		for (int i = 0; i < bucket_len; ++i) {
			int d = (arr[i] / digit) % b;

			/*int counter = buckets[d][bucket_len];
			buckets[d][counter] = arr[i];
			counter++;
			buckets[d][bucket_len] = counter;*/

			buckets[d][buckets[d][bucket_len]++] = arr[i];
		}
		int idx = 0;
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < buckets[i][bucket_len]; ++j) {
				arr[idx++] = buckets[i][j];
			}
			buckets[i][bucket_len] = 0;
		}

	}
	// Распределяет исходные данные по корзинам, основываясь на цифре числа. 
}


int main()
{
	srand(time(NULL));   // Change base for random number generator
	const int sizeN = 5; // row
	const int sizeM = 5; // col
	
	printf("Initial array: \n");
	arr1D = init1DArray(arr1D, sizeN);
	fill1DArray_int(arr1D, sizeN);
	print1DArray_int(arr1D, sizeN);
	
	printf("Sorted array: \n");

	// quickSortHoare(arr1D, 0, sizeN-1); 	// <-- 1a Hoare
	
	// quickSortLomuto(arr1D, 0, sizeN - 1); // <-- 1b Lomuto

	// thickSplit(arr1D, 0, sizeN - 1); // <-- 1c ThicSplit

	//improvedSorting(arr1D, 0, sizeN - 1); // <-- PROBLEM N1; Check it !!!

	//bucketSorting();

	print1DArray_int(arr1D, sizeN);

	return 0;
}
