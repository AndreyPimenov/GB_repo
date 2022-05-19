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

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

// Class Work - Trees
typedef struct Node {
	int key;
	struct Node* left;
	struct Node* right;
} TreeNode;

//TreeNode tree;
// вставка узла:
// шаг 1. Создание нового узла и подготовка его к существованию внутри дерева
// шаг 2. Поиск места для вставки
// шаг 3. Вставка узла, т.е. присваивание всех ссылок внутри и 
// снаружи вставляемого узла в нужном порядке

// правило для бинарного дерева поиска:
// ключи менее корневого - располагаются слева
// ключи более корневого - справа от него
// в ряде случаев могут попадть ключи равые корневому. но это
// для нетривиальных бинарных деревьях

// вставка узла на место листа дерева:
TreeNode* treeInsert(TreeNode* t, int data) {
	TreeNode* newNode;
	newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;

// для поиска места вставки нам понадобится два указателя
// 1-й на текущий узел при поиске
// 2-й на его родитель, чтобы правильно сообщить родительскому узлу
// о появлении наследника:
	TreeNode* current = t;
	TreeNode* parent = t;

// Если корень дерева пустой, то корнем дерева станет наш новый узел
// иначе нужно будет начинать искать
	if (t == NULL) {
		t = newNode;
	} else {
		while (current->key != data) {
			parent = current;
			if (current->key > data) {
				current = current->left;
				if (current == NULL) {
					// значит находимся в листовом элементе и можем добавить наслелдника
					parent->left = newNode;
					return t;
				}
			}
			else {
				current = current->right;
				if (current == NULL) {
					// значит находимся в листовом элементе и можем добавить наслелдника
					parent->right = newNode;
					return t;
				}
			}
		}
	}
	return t;
}

// вывод дерева как скобочной последовательности:
// эта последовательность формируется в коде 
// при обходе в прямом порядке:
void printTree(TreeNode* root) {
	if (root) {
		printf("%d", root->key);
		if (root->left || root->right) {
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

// Удаление узла:
// ситуация 1 - если этот узел - лист
// это возможно в случае двух подвидов - слева и справа от родителя
// то родителю присвоить NULL вместо ссылки на удаляемый узел
// ситуация 2 - удаление узла у которого всего один наследник
// может быть как правый так и левый	
// родителю вместо ссылки на удаляемый узел присвоить ссылку 
// на единственного наследника удаляемого узла
// ситуация 3 - удаление узла, у которого есть оба наследника
// необходимо найти подходящего преемника среди листов:
// меньший из больших
// больший из меньших
TreeNode* getSuccessor(TreeNode* node) {
	TreeNode* current = node->right; // сначала меньшего из больших
	TreeNode* parent = node;
	TreeNode* best = node;

	// меньший из больших:
	while (current != NULL) {
		parent = best;
		best = current;
		current = current->left;
	}
	if (best != node->right) {
		parent->left = best->right;
		best->right = node->right;
	}
	return best;
}

boolean deleteNode(TreeNode* root, int key) {
	TreeNode* current = root;
	TreeNode* parent = root;
	boolean isLeftChild = true;

	while (current->key != key) {
		parent = current;
		if (key < current->key) {
			current = current->left;
			isLeftChild = true;
		} else {
			current = current->right;
			isLeftChild = false;
		}
		if (current == NULL) 
			// означает что искомого ключа в дереве нет
			return false;
	}

	// случай простого листа:
	if (current->left == NULL && current->right == NULL) {
		if (current == root) {
			root = NULL;
		}
		else if (isLeftChild) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
	}

	// 4 варианта: 
	// удаляемый узел нах-ся справа или слева от родителя
	// у удаляемого узла остаются правый или левый потомок
	else if (current->right == NULL) {
		if (isLeftChild) {
			parent->left = current->left;
		}
		else {
			parent->right = current->left;
		}
	}
	else if (current->right == NULL) {
		if (isLeftChild) {
			parent->left = current->right;
		}
		else {
			parent->right = current->right;
		}
	}

	// крайняя ситуация, когда удаляемый узел имеет два наследника:
	// в этом случае берем наиболее подходящий (см. выше) лист
	// и подставляем его в качестве удаляемого узла
	else {
		TreeNode* successor = getSuccessor(current);
		if (current == root) {
			root = successor;
		}
		else if (isLeftChild) {
			parent->left = successor;
		}
		else {
			parent->right = successor;
		}
		successor->left = current->left;
	}
	return true;
}

int main(const int argc, const char** argv) {
	TreeNode* tree = 0; 
	tree= treeInsert(tree, 10);

	treeInsert(tree, 5);
	treeInsert(tree, 7);
	treeInsert(tree, 3);
	treeInsert(tree, 2);
	treeInsert(tree, 1);
	treeInsert(tree, 9);
	treeInsert(tree, 12);
	treeInsert(tree, 8);
	printTree(tree);
	printf("\n");
	deleteNode(tree, 12);
	printTree(tree);

	return 0;
}
