#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
	return 0;
}
