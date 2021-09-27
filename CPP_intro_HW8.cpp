// HW8:
// Cделать решение на поле 4х4 или 5х5 или на динамическом поле, размер которого ввел пользователь.
// Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3 - 5.

#include <iostream>
#include <string>

//using namespace std;


enum gameSymbols { empty, X, O,};
bool orderFlg = 1; // 1 - 1st player "X"; 0 - 2nd player "O" 
int orderStep; // th
int x = 0;
int y = 0;
bool victoryFlg = false;

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
		for (int c = 0; c < Colomns; c++) {
			std::cout << printSymbol(array[r][c]) << "  ";
		}
		std::cout << std::endl;
	}
}

bool gameSymbolChanged(gameSymbols** array, int Rows, int Colomns, bool player) {
	
	std::cout << "Enter the x coordinate:" << std::endl;
	std::cin >> x;

	std::cout << "Enter the y coordinate:" << std::endl;
	std::cin >> y;
	// 1. cell should be empty; 2. x has to relevant; 3. y has to be relevent.
		if ((array[x][y] == gameSymbols::empty) && (0 <= x < Rows) && (0 <= y < Colomns)) {
			if (player == 1) {
				array[x][y] = gameSymbols::X;
			}
			if (player == 0) {
				array[x][y] = gameSymbols::O;
			}
			return true;
		}
		else {
			std::cout << "Same player try again" << std::endl;
			return false;
		}
}

bool playerMakeStep(gameSymbols** array, int Rows, int Colomns, bool player) {
	
	if (player == 1) {
		std::cout << "1st player make step: " << std::endl;
		// true = step was succesfully finished; false = same player needs to make another step:
		
		if (gameSymbolChanged(array, Rows, Colomns, player)) {
			
			player = !player;
			orderStep++;
		}
		else { player = player; }
		
	}

	else if (player == 0) {
		std::cout << "2nd player make step: " << std::endl;
		// true = step was succesfully finished; false = same player needs to make another step:

		if (gameSymbolChanged(array, Rows, Colomns, player)) {
			
			player = !player;
			orderStep++;
		}
		else { player = player; }
	}
	return player;
}

bool vectorCheck(gameSymbols* vector, int Size) {
	gameSymbols temp = vector[Size]; // берем послений элемент вектора и проходим весь вектор на его равенство:

	for (int i = 0; i < Size; i++) {
		if ((vector[i] != gameSymbols::empty) && (vector[i] == temp)) {
			
		}
		else {
			return false;
		}
		return true;
	}
}

bool playerVictoryCheck(gameSymbols** array, int Rows, int Colomns, int x_internal, int y_internal, int vectorSize) {
	// creating array: 
	gameSymbols* checkingArray = new gameSymbols[vectorSize]; // creating 1D array of elements to check

	// horizontal check:
	{
		std::cout << "vertical: ";
		for (int i = 0; i < Rows; i++) {
			//std::cout << printSymbol(array[i][y_internal]);
			checkingArray[i] = array[i][y_internal];
			std::cout << printSymbol(checkingArray[i]);
		}
		std::cout << std::endl;

		// return bool function (checkingArray);
		return vectorCheck(checkingArray, vectorSize);
	};
	
	// vertical check:
	{
		std::cout << "horizontal: ";
		for (int j = 0; j < Colomns; j++) {
			//std::cout << printSymbol(array[x_internal][j]);
			checkingArray[j] = array[x_internal][j];
			std::cout << printSymbol(checkingArray[j]);
		}
		std::cout << std::endl;

		// return bool function (checkingArray);
		return vectorCheck(checkingArray, vectorSize);
	};

	// diagonal check from the top left to the bottom right: (diagonalTL2BR)
	{
		int elementCounting = 0; // in some cases diagonal less than vector to win in this case we do not check it

		std::cout << "diagonal from top left to bottom right: ";

		// create operators:
		int x_check = x_internal; int y_check = y_internal; 
		
		// x and y both decrease:
		while ((x_check != -1) && (y_check != -1)) {
			std::cout << printSymbol(array[x_check][y_check]);
			x_check--;
			y_check--;
			elementCounting++;
		}

		// reset operators:
		x_check = x_internal+1; y_check = y_internal+1; 

		// x and y both increase:
		while ((x_check < Rows) && (y_check < Colomns)) {
			std::cout << printSymbol(array[x_check][y_check]);
			x_check++;
			y_check++;
			elementCounting++;
		}
		std::cout << std::endl;
		//std::cout << elementCounting << std::endl;

		// записать в массив:
		if (elementCounting >= vectorSize) {
			for (int k = 0; k < vectorSize; k++) {

				// create operators:
				int x_check = x_internal; int y_check = y_internal;

				while ((x_check != -1) && (y_check != -1)) {
					//std::cout << printSymbol(array[x_check][y_check]);
					checkingArray[k] = array[x_check][y_check];
					//std::cout << "diagonal = " << printSymbol(checkingArray[k]);
					x_check--;
					y_check--;
					k++;
			
				}

				x_check = x_internal + 1; y_check = y_internal + 1;

				while ((x_check < Rows) && (y_check < Colomns)) {
					//std::cout << printSymbol(array[x_check][y_check]);
					checkingArray[k] = array[x_check][y_check];
					//std::cout << "diagonal = " << printSymbol(checkingArray[k]);
					x_check++;
					y_check++;
					k++;
					
				}
				std::cout << std::endl;
			}
		}

		
		// return bool function (checkingArray);
		return vectorCheck(checkingArray, vectorSize);
	};
	
	// diagonal check from the bottom left to the top right: (diagonalBL2TR)
	{
		int elementCounting = 0; // in some cases diagonal less than vector to win in this case we do not check it


		std::cout << "diagonal from the bottom left to the top right: ";
		// reset operators:
		int x_check = x_internal; int y_check = y_internal;

		// x and y both decrease:
		while ((x_check < Rows) && (y_check != -1)) {
			std::cout << printSymbol(array[x_check][y_check]);
			x_check++; 
			y_check--; 
			elementCounting++;
		}

		// reset operators:
		x_check = x_internal-1; y_check = y_internal+1;

		// x and y both increase:
		while ((x_check != -1) && (y_check < Colomns)) {
			std::cout << printSymbol(array[x_check][y_check]);
			x_check--; 
			y_check++; 
			elementCounting++;
		}
		std::cout << std::endl;
		//std::cout << elementCounting << std::endl;

		// записать в массив:
		if (elementCounting >= vectorSize) {
			for (int k = 0; k < vectorSize; k++) {


				int x_check = x_internal; int y_check = y_internal;

				while ((x_check < Rows) && (y_check != -1)) {
					checkingArray[k] = array[x_check][y_check];
					//std::cout << "diagonal \ = " << printSymbol(checkingArray[k]);

					x_check++;
					y_check--;
					k++;
				}

				// reset operators:
				x_check = x_internal - 1; y_check = y_internal + 1;

			
				while ((x_check != -1) && (y_check < Colomns)) {
					

					checkingArray[k] = array[x_check][y_check];
					//std::cout << "diagonal \ = " << printSymbol(checkingArray[k]);

					x_check--;
					y_check++;
					k++;
				}
				std::cout << std::endl;
			}
		}

		// return bool function (checkingArray);
		return vectorCheck(checkingArray, vectorSize);
	};

	// emptying space:
	delete[] checkingArray;
	checkingArray = nullptr;

	return false;
}


void deleteGameField(gameSymbols** data, int Rows)
{
	for (int r = 0; r < Rows; r++) delete[] data[r];
	delete[] data;
}


int main() {
	int fieldSize = 3;
	int vectorSize = 3;

	// 1st Block - Initialisation of the field & victory vector sizes:
	std::cout << "Enter the size of square field: " << std::endl;
	std::cin >> fieldSize;
	fieldSize = (static_cast<int>(fieldSize) == fieldSize) ? fieldSize : 3; // filedSize must be integer

	std::cout << "Enter the size of the sequence enought for victory " << std::endl;
	std::cin >> vectorSize;

	

	vectorSize = ((static_cast<int>(vectorSize) == vectorSize) && (static_cast<int>(vectorSize) < fieldSize)) ? vectorSize : 3;
	 
    gameSymbols ** gameField =  fieldGeneration(fieldSize, fieldSize);
	gameFieldUpdate(gameField, fieldSize, fieldSize); // just ofr demonstration initial field

	std::cout << "Show must go on !!! " << std::endl;

	

	// 2nd Block - Game:
	while ((orderStep < fieldSize * fieldSize) && (victoryFlg == false)) {

		orderFlg = playerMakeStep(gameField, fieldSize, fieldSize, orderFlg);
		
		gameFieldUpdate(gameField, fieldSize, fieldSize);
		//std::cout << "we use x = " << x << " " << "we use y = " << y << std::endl;

		
		if (orderStep >= (vectorSize * 2 - 1)) { // <<--- there is no reason to check it before
			victoryFlg = playerVictoryCheck(gameField, fieldSize, fieldSize, x, y, vectorSize);
			//std::cout << "HERE" << std::endl;
		}
	
		//std::cout << "& HERE" << std::endl;
	}

	// 3rd Block - empty space after the working process:

	
	deleteGameField(gameField, fieldSize); 
	gameField = nullptr;
	return 0; 
}


// PS:
// 1. resizing the array: 
// https://stackoverflow.com/questions/42238712/change-array-size-c#:~:text=To%20resize%20an%20array%20you,%5Bold_size%5D%3B%20%2F%2F...
// 2. array intialization through link / function:
// https://coderoad.ru/31230610/C-%D0%B8%D0%BD%D0%B8%D1%86%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2%D0%B0-%D0%BF%D0%BE-%D1%81%D1%81%D1%8B%D0%BB%D0%BA%D0%B5-%D1%87%D0%B5%D1%80%D0%B5%D0%B7-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8E
// 3. проверка на целочисленный тип данных:
// https://coderoad.ru/784563/C-%D0%BF%D1%80%D0%BE%D0%B2%D0%B5%D1%80%D0%B8%D1%82%D1%8C-%D1%8F%D0%B2%D0%BB%D1%8F%D0%B5%D1%82%D1%81%D1%8F-%D0%BB%D0%B8-%D1%87%D0%B8%D1%81%D0%BB%D0%BE-%D0%B8%D0%BD%D1%82-%D1%84%D0%BB%D0%BE%D0%B0%D1%82

	
