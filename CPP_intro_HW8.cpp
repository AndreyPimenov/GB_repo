// HW8:
// Cделать решение на поле 4х4 или 5х5 или на динамическом поле, размер которого ввел пользователь.
// Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3 - 5.

#include <iostream>
#include <string>

//using namespace std;

struct gameField {
	
	enum gameSymbols { X, O, _ };
	int sumOrder;
	const int SIZE;
	gameSymbols field_arr[gameField::SIZE][gameField::SIZE];

	typedef unsigned short x_coordinate;
	typedef unsigned short y_coordinate;

	enum playerOrder {X_player, O_player};

};

int main() {

	int fieldSize = 3;
	std::cout << "Enter the size of square field: " << std::endl;
	std::cin >> fieldSize; // add checking the size

	std::cout << "Choose the player: " << std::endl;
	std::cin >> fieldSize; // add checking the size

	return 0; 
}



	

// Version 2 - after webinar:


