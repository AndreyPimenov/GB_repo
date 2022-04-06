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

void fillArray(char** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			*((*(array + i)) + j) = '*';
		}
	}
}

void printArray(char** array, const int row, const int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("[%c]", *((*(array + i)) + j));
		}
		printf("\n");
	}
}




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
	const int row = 3;
	const int col = 5;
	char** arr = initArray(arr, row, col);
	fillArray(arr, row, col);
	printArray(arr, row, col);


	return 0;
}
