/*
1) Описать очередь с приоритетным исключением
2) Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main, 
а также функции, необходимые для работы приоритетной очереди и перевода систем счисления
*/

// Resources:
// Queue - https://codechick.io/tutorials/dsa/dsa-priority-queue 
// Queue C - https://youtu.be/aUKoTGnzLic 

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

int** arr2D; // we have to initialise this variable here, to compiling code in MVS-2019
int* arr1D;

#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

int cursor = -1;
T Stack[SIZE];
typedef int boolean;

/*
T Queue[SIZE];
int first = 0;
int end = -1;
int items_q = 0;

boolean enqueue(T data) {
	// функция добавления
	// проверяем, что очередь не заполнена
	if (items_q == SIZE) {
		printf("%s \n", "Queue is full");
		return false;
	}
	if (end == SIZE - 1) {
		end = -1;
	}
	Queue[++end] = data;
	items_q++;
	return true;
}

T dequeue() {
	if (items_q == 0) {
		printf("%s \n", "Queue is empty");
		return -1;
	}
	else {
		char tmp = Queue[first++];
		first %= SIZE; // if (first == SIZE) first = 0; 
		items_q--;
		return tmp;
	}
}

*/

boolean push(T data) {
	// наличие свободного места в массиве:
	if (cursor < SIZE) {
		Stack[++cursor] = data;
		return true;
	}
	else {
		printf("%s \n", "Stack overflow");
		return false;
	}
}

T pop() {
	// проверим, что возвращаемый стек не пуст:
	if (cursor != -1) {
		return Stack[cursor--];
	}
	else {
		printf("%s \n", "Stack is empty");
		return -1; // такого значения в стеке точно быть не можеь 
	}
}

// очередь:
// ключ - приоритет
// значение  - непосредственно само значение ячейки

// очередь с приоритетом включением:
#define SZ 10
typedef struct {
	int priority;
	int data;
} Node;

Node* arr[SZ];
int head; // индекс головы очереди
int tail; // индекс хвоста очередиъ
int items; // текущее кол-во элементов в очереди

void init() {
	for (int i = 0; i < SZ; ++i) {
		arr[i] = NULL;
	}
	head = 0;
	tail = 0;
	items = 0;
}

void insert_qin(int priority, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->priority = priority;
	int flag; // место вставки

	// Если очередь пустая, то положим новый элемент в хвост очереди
	// Увеличим индекс хвоста и кол-во элементов в очереди
	if (items == 0) {
		arr[tail++] = node;
		items++;
	}
	else if (items == SZ) {
		printf("%s \n", "Queue is full");
		return;
	}
	else {
		int i = 0;
		int idx = 0;
		Node* tmp;
		for (i = head; i < tail; ++i) {
			idx = i % SZ;
			if (arr[idx]->priority > priority) break;
			else idx++;
		}
		flag = idx % SZ;
		i++;
		while (i <= tail) {
			idx = i % SZ;
			tmp = arr[idx];
			arr[idx] = arr[flag];
			arr[flag] = tmp;
			i++;
		}
		arr[flag] = node;
		items++;
		tail++;
	}
}

Node* remove_qin() {
	if (items == 0) {
		return NULL;
	}
	else {
		int idx = head++ % SZ;
		Node* tmp = arr[idx];
		arr[idx] = NULL;
		items--;
		return tmp;
	}
}

// очередь с приоритетом исключением:

void insert_qout(int priority, int data) {
	// выделение памяти на ячейку узла внутри очереди, назначение переменных:
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;  
	node->priority = priority; // arr[i] = node

	// Если очередь пустая, то положим новый элемент в хвост очереди
	// Увеличим индекс хвоста и кол-во элементов в очереди:
	if (items == 0) {
		arr[tail++] = node;
		items++;
	}
	else if (items == SZ) {
		printf("%s \n", "Queue is full");
	}
	else {
		arr[items] = node;
		items++;
	}
	tail++;
}

Node* remove_qout() {	
	int flag; // место удаления элемента
	
	// this function I realised with your support:
	if (items == 0) {
		printf("%s \n", "Queue is empty");
		return NULL;
	}

	int max = arr[0]->priority;
	int idx = 0;

	for (int i = 1; i < items; ++i) {
		if (arr[i]->priority > max) {
			max = arr[i]->priority;
			idx = i;
		}
	}

	Node* tmp = arr[idx];

	while (idx < items) {
		arr[idx] = arr[idx + 1];
		idx++;
	}
				
	items--;
	tail--; 
	return tmp;
}

void printQueue() {
	printf("{ ");
	for (int i = 0; i < items; ++i) {
		if (arr[i] == NULL) {
			printf("[*,*]");
		}
		else {
			printf("[%d,%d]", arr[i]->priority, arr[i]->data);
		}

	}
	printf("} \n");
}

// перевод из десятичной в двоичную с ис-ем стека:
// шаг 1 - задаем большой стек - DONE BEFORE
// шаг 2 - пишем push() - запись в стек - DONE BEFORE
// шаг 3 - пишем pop() - удаление из стека - DONE BEFORE
// шаг 3 - делим число на два и записываем в стек остаток от деления, повторяем в цикле пока не пройдем все число

void decToBin(int a) {
	while (a >= 1) {
		push(a % 2);
		a /= 2;
	}

}



int main(const int argc, const char** argv) {

	// Class work:
	/*
	push('a');
	push('b');
	push('c');
	push('d');
	push('e');
	push('f');
	while (cursor != -1) {
		printf("%c,", pop());
	}
	*/

	/*
	int i = 0;
	while (i < 5) {
		enqueue('a');
		enqueue('b');
		enqueue('c');
		enqueue('d');
		enqueue('e');
		enqueue('f');
		while (items > 0) {
			printf("%c,", dequeue());
		}
		printf("\n");
		i++;
	}
	*/
	// очередь с приоритетом включением:
	/*
	init();
	insert_qin(1, 11);
	insert_qin(5, 22);
	insert_qin(3, 123);
	insert_qin(4, 33);
	insert_qin(2, 15);
	insert_qin(4, 19);
	insert_qin(5, 21);
	insert_qin(7, 51);
	insert_qin(2, 71);
	insert_qin(8, 45);
	printQueue();
	for (int i = 0; i < 7; ++i) {
		Node* n = remove_qin();
		printf("priority = %d, data = %d \n", n->priority, n->data);
	}
	printQueue();
	*/

	// Home Work:
	// очередь с приоритетом исключением:
	init();
	insert_qout(2, 12);
	insert_qout(1, 15);
	insert_qout(4, 22);
	insert_qout(7, 12);
	insert_qout(2, 12);
	insert_qout(1, 15);
	insert_qout(4, 22);
	insert_qout(7, 12);
	insert_qout(5, 32);
	insert_qout(6, 42);
	printQueue();

	remove_qout();
	remove_qout();
	printQueue();
	
	// перевод из десятичной в двоичную с ис-ем стека:
	
	printf("15 in dec, in bin it is ");
	decToBin(15);
	int count = cursor;
	for (int i = 0; i <= count; ++i) {
		printf("%d", pop());
	}
	
	return 0;
}
