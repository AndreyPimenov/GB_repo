#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;


// Class work:
// 1 - односвязные
// 2 - двусвязные
// 3 - циклические списки
// 4 - стек на основе односвязного списка
// 5 - очередь на основе двухсвязного списка

typedef struct Node {
	int data;
	struct Node *next;
}; Node;

typedef struct List {
	Node* head;
	int size;
}; List;

void init(List* lst) {
	lst->head = NULL;
	lst->size = 0;
}

void insertList(List *lst, int data) {
	Node* newOne = (Node*) malloc(sizeof(Node));
	newOne->data = data;
	newOne->next = NULL;

	Node* currentOne = lst->head;
	if (currentOne == NULL) {
		lst->head = newOne;
		lst->size++;
		return;
	}
	else {
		while (currentOne->next != NULL) {
			currentOne = currentOne->next;
		}
		currentOne->next = newOne;
		lst->size++;
	}
}

// удаление по значению:
Node* removeNode(List* lst, int data) {
	Node* currentOne = lst->head;
	Node* previousOne = NULL;
	if (currentOne == NULL) {
		return NULL;
	}

	while (currentOne->next != NULL && currentOne->data != data) {
		previousOne = currentOne;
		currentOne = currentOne->next;
	}

	if (currentOne->data != data) {
		return NULL;
	}

	if (currentOne == lst->head) {
		lst->head = currentOne->next;
		lst->size--;
		return currentOne;
	}

	previousOne->next = currentOne->next;
	lst->size--;
	return currentOne;
}

void printNode(Node* n) {
	if (n == NULL) {
		printf("[]");
		return;
	}
	printf("[%d]", n->data);
}

void printList(List* lst) {
	Node* currentOne = lst->head;
	if (currentOne == NULL) {
		printNode(currentOne);
	}
	else {
		do {
			printNode(currentOne);
			currentOne = currentOne->next;
		} while (currentOne != NULL);
	}
	printf("Size: %d \n", lst->size);
}

// Home work:
// 1 - Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры правильных скобочных выражений : (), ([])(), {}(), ([{}]), 
// неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
// Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]
// 2 - Создать функцию, копирующую односвязный список(без удаления первого списка).
// 3 - Реализуйте алгоритм, который определяет, отсортирован ли связный список.
Node* removeLastNode(List* lst) {
	Node* currentOne = lst->head;
	Node* previousOne = NULL;
	if (currentOne == NULL) {
		return NULL;
	}

	while (currentOne->next != NULL) {
		previousOne = currentOne;
		currentOne = currentOne->next;
	}

	if (currentOne == lst->head) {
		lst->head = currentOne->next;
		lst->size--;
		return currentOne;
	}

	previousOne->next = currentOne->next;
	lst->size--;
	return currentOne;
}

int braketsCheck(char* expression) {
	const int TYPES = 3;
	char brackets[][2] = {
		{'(',')'},
		{'[',']'},
		{'{','}'}
	};

	List* st = (List*)malloc(sizeof(List));
	init(st);

	int countIndx = 0;
	while (*expression != '\n') {
		for (int i = 0; i < TYPES; ++i) {
			if (*expression == brackets[i][0]) {
				insertList(st, i); // pushOneLinkStack(st, i);
			}
		}
		for (int i = 0; i < TYPES; ++i) {
			if (*expression == brackets[i][1]) {
				if (st->size == 0) {
					return countIndx; // )(
				}
				if (i == st->head->data){
					removeLastNode(st);	
				}
				else {
					return countIndx;
				}
			}
			expression++;
			countIndx++;
		}
		if (st->size != 0) {
			return 0;
		}
		return -1;
	}
}

void copyList(List* from, List* to){
	int size = from->size;
	Node* currentOne = from->head;
	while (size != 0 ) {
		for (int i = 0; i < size - 1; ++i) {
			currentOne = currentOne->next;
		}
		insertList(to, currentOne->data);
		size--;
		currentOne = from->head;
	}
}

boolean isSorted(List* lst) {
	Node* currentOne = lst->head;
	while (currentOne->next != NULL) {
		if (currentOne->data > currentOne->data)
			return false;
		currentOne = currentOne->next;
	}
}

char* expression;

int main(const int argc, const char** argv) {
	// Class work:
	// Выделим участок памяти для LIST:
	List* lst = (List*)malloc(sizeof(List));
	init(lst);
	printList(lst);

	insertList(lst, 1);
	printList(lst);

	insertList(lst, 5);
	printList(lst);

	insertList(lst, 3);
	printList(lst);

	printNode(removeNode(lst, 1)); printf("<- removed mode\n");
	printList(lst);

	// Home work:
	/*
	braketsCheck( expression: "()");
	printf("(): %d \n", braketsCheck(expression: "()"));
	printf("(: %d \n", braketsCheck(expression: "("));
	printf("{}(]: %d \n", braketsCheck(expression: "{}(]"));
	printf("{ ( [ { } [] ] ( }: %d \n", braketsCheck(expression: "{ ( [ { } [] ] ( }"));
	printf("[2/{5*(4+7)}]: %d \n", braketsCheck(expression: "[2/{5*(4+7)}]"));
	printf("[2/{5*[4+7)}]: %d \n", braketsCheck(expression: "[2/{5*[4+7)}]"));
	*/

	List* first = (List*)malloc(sizeof(List));
	init(first);

	List* second = (List*)malloc(sizeof(List));
	init(second);

	for (int i = 9; i > 1; --i) {
		insertList(first, i);
	}

	printList(first);
	copyList(first, second);
	printList(second);
	printf("%s \n", isSorted(first) ? "true" : "false");

	return 0;
}
