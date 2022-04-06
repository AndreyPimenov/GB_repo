#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <stdio.h>  // определение макросов и констант   
#include <stdlib.h> // выделение памяти и контроль процесса выплнения программы 

// Class Work:

int searchNum(int* array, int len, int value) {
	for (int i = 0; i < len; ++i) {
		if (array[i] == value){
			return i;
		}
	}
	return -1;
}

float mean(int* array, int len) {
	float sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += array[i];
	}
	return sum / len;
}

char** initArray(char** array, const int row, const int col) {
	array = (char**) calloc(sizeof(char*), row);
	for (int i = 0; i < row; ++i) {
		*(array + i) = (char*) calloc(sizeof(char), col);
	}
	return array;
}

void fillArray_char(char** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			*((*(array + i)) + j) = '*';
		}
	}
}

void printArray_char(char** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("[%c]", *((*(array + i)) + j));
		}
		printf("\n");
	}
}

void fillArray_int(char** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			*((*(array + i)) + j) = ((i + 1) * (j + 1));
		}
	}
}

void printArray_int(char** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("[%4d]", *((*(array + i)) + j));
		}
		printf("\n");
	}
}

void changeCols(char** array, int row, int col, int from, int to ) {
	char temp;
	for (int i = 0; i < row; ++i) {
		temp = *((*(array + i)) + from);
		*((*(array + i)) + from) = *((*(array + i)) + to);
		*((*(array + i)) + to) = temp;

	}
}




char** arr; // for compiling in MVS, it needed to be a global variable; but in others compliers it could be local inside main() 


int main(const int argc, const char** argv) { // https://ru.stackoverflow.com/questions/227712/Для-чего-в-main-int-argc-char-argv

	// one - dimensional arrays:
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int b[10] = { 0 };
	int c[] = { 0,1,2,3,4,5 };
	int d[10];

	d[0] = 10;
	d[1] = 20;
	d[2] = 30;
	for (int i = 3; i < 9; ++i) {
		d[i] = (i + 1) * 10;
	}

	printf("index of 5 in a: %d \n", searchNum(a, 10, 5));
	printf("index of 21 in d: %d \n", searchNum(d, 10, 21));
	printf("mean of d: %f \n", mean(d, 10));
	printf("mean of c: %f \n", mean(c, 6));

	// many - dimensional arrays:
	const int row = 10;
	const int col = 10;
	arr = initArray(arr, row, col);
	fillArray_char(arr, row, col);
	printArray_char(arr, row, col);

    // multi table:
	arr = initArray(arr, row, col);
	fillArray_int(arr, row, col);
	printArray_int(arr, row, col);

	// рокировка колонок таблицы:
	changeCols(arr, row, col, 2, 8);
	printArray_int(arr, row, col);

	// треугольные массивы: 
	// B: [A(1,0), A(2,0), A(2,1), A(3,0), A(3,1), A(3,2), ... ]
	// поиск элемента в треугольном массиве:
	// (( r - 1)*2 + (r-1))/2 + c) 

	return 0;
}
