// HW8:
// Cделать решение на поле 4х4 или 5х5 или на динамическом поле, размер которого ввел пользователь.
// Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3 - 5.

#include <iostream>
#include <string>

//using namespace std;

enum gameSymbols { empty, X, O,};
bool orderFlg = 1; // 1 - 1st player "X"; 0 - 2nd player "O" 

char printSymbol(gameSymbols cell) {
	// symbol printing:
	if (cell == gameSymbols::empty)
		return '-';
	if (cell == gameSymbols::X)
		return 'X';
	if (cell == gameSymbols::O)
		return '0';
}

gameSymbols** fieldGeneration(int Rows, int Colomns) {
	// initialization of the field array:
	gameSymbols** gameArray = new gameSymbols * [Rows];

	for (int r = 0; r < Rows; r++) {
		gameArray[r] = new gameSymbols[Colomns]();
		for (int c = 0; c < Colomns; c++) {
			gameArray[r][c] = gameSymbols::empty;
			//std::cout << " r = " << r << " c= " << c << " this element: " << printSimbol(gameArray[r][c]) << std::endl;
		}
	}

	return gameArray;
}

void gameFieldUpdate(gameSymbols** array, int Rows, int Colomns) {
	std::cout << "This is relevant game field: " << std::endl;
	for (int r = 0; r < Rows; r++) {
		
		array[r] = new gameSymbols[Colomns]();
		for (int c = 0; c < Colomns; c++) {
			std::cout << printSymbol(array[r][c]) << "  ";
		}
		std::cout << std::endl;
	}
}

// free space:
void deleteGameField(gameSymbols** data, int Rows)
{
	for (int r = 0; r < Rows; r++) delete[] data[r];
	delete[] data;
}


int main() {

	int fieldSize;
	std::cout << "Enter the size of square field: " << std::endl;
	std::cin >> fieldSize;
	// filedSize must be integer type or else it should be equal 3; 
	fieldSize = (static_cast<int>(fieldSize) == fieldSize) ? fieldSize : 3;
		
	// creating customized field:
    gameSymbols ** gameField =  fieldGeneration(fieldSize, fieldSize);

	// do smth:
	gameFieldUpdate(gameField, fieldSize, fieldSize);

	// game victory conditions
	deleteGameField(gameField, fieldSize); 

	return 0; 
}


// PS:
// 1. resizing the array: 
// https://stackoverflow.com/questions/42238712/change-array-size-c#:~:text=To%20resize%20an%20array%20you,%5Bold_size%5D%3B%20%2F%2F...
// 2. array intialization through link / function:
// https://coderoad.ru/31230610/C-%D0%B8%D0%BD%D0%B8%D1%86%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2%D0%B0-%D0%BF%D0%BE-%D1%81%D1%81%D1%8B%D0%BB%D0%BA%D0%B5-%D1%87%D0%B5%D1%80%D0%B5%D0%B7-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8E
// 3. проверка на целочисленный тип данных:
// https://coderoad.ru/784563/C-%D0%BF%D1%80%D0%BE%D0%B2%D0%B5%D1%80%D0%B8%D1%82%D1%8C-%D1%8F%D0%B2%D0%BB%D1%8F%D0%B5%D1%82%D1%81%D1%8F-%D0%BB%D0%B8-%D1%87%D0%B8%D1%81%D0%BB%D0%BE-%D0%B8%D0%BD%D1%82-%D1%84%D0%BB%D0%BE%D0%B0%D1%82

