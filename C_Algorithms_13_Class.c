// Графы
#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include "geek.h"

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//
//
//int random(int min, int max) {
//	int number = min + rand() % (max - min);
//	return number;
//}
//
//void swapInt(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}

// ГРАФЫ 
//
// Граф - это совокупность множества точек - вершин,
// и множества - ребер, которые их соединяют
// 
// Хар-ки вершин:
// Две вершины, соединенные ребром - наз-ся смежными
// Степень вершины - кол-во исходящих из нее ребер
// Полустепень захода - кол-во ребер входящих в вершину
// В направленном графе будут начальные и конечные вершины
// 
// Хар-ки ребер: 
// вес - числовое значение, которым можно характеризовать например время
// за которое можно добраться от одной вершины до другой
// направление - т.е. ребро ориентировано и представляет собой вектор
// ребра имеющие одинаковые концевые вершины наз-ся параллельными
// подграф графа G
// путь на графе. Затраты пути складываются из затрат пройденных ребер
// 
// Ориентированный граф и неориентированный граф
// В неориентированном графе полустеперь захода равна степени вершины
// Полный граф - когда каждая вершина в графе имеет ребра ко всем другим вершинам
// Связный граф - когда можно добраться из любой вершине к любой другой вершине
// Есть сильносвязные, слабосвязные и несвязные графы
//
// Матрица смежности - способ представления графа в виде матрицы
// матрица смежности не содердащей петел и кратных ребер явл-ся бинарной



// Обход графа в глубину или поиск в глубину
// Принцип простой: если из текущей вершины есть ребра в 
// непройденные, вершины то идем туда. иначе - возвращаемся назад
// 
// Поиск выхода из лабиринта можно сравнить с поиском в глубину
// шаг 1. Посетить смежную вершину не посещавшуюся ранее, изменить ей статус на посещенную
// повторяем это действие до тупика
// шаг 2. Если выполнение первого действия невозможно. то вернуться к предыдущей вершине
// и снова попыться повторить первое действие
// шаг 3. Если выполнение действий 1 и 2 невозможно - обход закончен

// пусть есть ориентированный граф состоящий из 6 вершин
const int n = 6;
int matrix[n][n] = {
	{0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{1, 0, 1, 0, 0, 0},
};

int visited[n] = { 0 }; // 0 - вершина не посещалась

// обход графа в глубину:
void depthTravers(int startIdx) {
	int rebro;
	printf("%d", startIdx);

	visited[startIdx] = 1;

	for (rebro = 0; rebro < n; ++rebro) {
		if (matrix[startIdx][rebro] == 1 && !visited[rebro]) {
			depthTravers(rebro);
		}
	}
}

void resetArr() {
	for (int i = 0; i < n; ++i) {
		visited[i] = 0;
	}
}

// обход графа в ширину:
//шаг 1. Посетить смежную текущей вершину, не посещавшуюся ранее и
//изменить ей статус на посещенную
//шаг 2. Делаем текущую вершину - первой посещенной после текущей
//выполнить шаг 1. Если выполнение первого дейсвтия невозможно. то переходим ко
//второй посещееной вершиной от текущей делаем 1-е
//шаг 3. Если нельзя 1 и 2 то граф пройден
//
// Для хранения будем использовать динамическую структуру даннных 
// очередь на основе двухсвязного списка
// статус вершины мы будем хранить в массиве и всегда будем знать
// посещаалсь ли вершина ранее или нет

void clearVisited(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = 0;
	}
}

void widthTravers(int** matrix, int start, const int size) {
	TwoLinkList* queue = (TwoLinkList*)malloc(sizeof(TwoLinkList));
	initTwoLinkList(queue);
	visited[size];
	clearVisited(visited, size);

	// Переход к сути алгоритма:
	TwoLinkEnqueue(queue, start);
	while (queue->size > 0) {
		int index = TwoLinkDequeue(queue);
		if (visited[index] == 1) continue;

		visited[index] = 1;
		printf("%d ", index);
		for (int i = 0; i < size; ++i) {
			if (get2dInt(matrix, index, i) == 1 && visited[i] == 0)
				TwoLinkEnqueue(queue, i);
		}
	}

}


int main(const int argc, const char** argv) {	
	
	{
		depthTravers(0);
		resetArr();
		printf("\n");

		depthTravers(2);
		resetArr();
		printf("\n");

		depthTravers(1);
		printf("\n");

	}
	
	{
		const int SZ = 6;
		int** adjacency = init2dIntArray(adjacency, SZ, SZ);

		set2dInt(adjacency, 0, 1, 1);
		set2dInt(adjacency, 0, 2, 1);
		set2dInt(adjacency, 1, 3, 1);
		set2dInt(adjacency, 1, 4, 1);
		set2dInt(adjacency, 1, 5, 1);
		set2dInt(adjacency, 2, 5, 1);
		set2dInt(adjacency, 3, 0, 1);
		set2dInt(adjacency, 5, 4, 1);

		widthTravers(adjacency, 0, SZ);
		printf("\n");
		widthTravers(adjacency, 3, SZ);
		printf("\n");
		widthTravers(adjacency, 1, SZ);
		printf("\n");

	}

	return 0;
}