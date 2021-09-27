/* #include <iostream>

int main(){
    int* ptrArr; // pointer to array
    int n = 0; // the size of the array

    std::cout << "Enter the size of array: " << "\n";
    std::cin >> n;

    if (n > 0){
        ptrArr = new (std::nothrow) int[n];

        // Working with the array:
        ptrArr[0] = 100;
        std::cout << "ptrArr[0] = " << ptrArr[0] << " ";

        //
        delete[] ptrArr;
        ptrArr = nullptr;
    }
    else{
        std::cout << "Error";
    }


  return 0;
}
 */

// HW8:
// Cделать решение на поле 4х4 или 5х5 или на динамическом поле, размер которого ввел пользователь.
// Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3 - 5.

#include <iostream>
#include <string>

//using namespace std;

// Block of global variables:
enum gameSymbols { empty, X, O,};
bool playerOrder = 1; // 1 - 1st player "X"; 0 - 2nd player "O"
int stepCounter;
int x = 0;
int y = 0;
bool victoryFlg = false;

//Block of functions:
char printSymbol(gameSymbols cell) {
    // symbol printing:
    if (cell == gameSymbols::empty)
        return '-';
    if (cell == gameSymbols::X)
        return 'X';
    if (cell == gameSymbols::O)
        return '0';
}

gameSymbols** fieldGeneration(int Rows, int Columns) {
    // initialization of the field array:
    gameSymbols** gameArray = new gameSymbols * [Rows];
    for (int r = 0; r < Rows; r++) {
        gameArray[r] = new gameSymbols[Columns]();
        for (int c = 0; c < Columns; c++) {
            // initially each element is empty:
            gameArray[r][c] = gameSymbols::empty;
        }
    }
    return gameArray;
}

void gameFieldUpdate(gameSymbols** array, int Rows, int Columns) {
    std::cout << "This is relevant game field: " << std::endl;
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            std::cout << printSymbol(array[r][c]) << "  ";
        }
        std::cout << std::endl;
    }
}

bool gameSymbolChanged(gameSymbols** array, int Rows, int Columns, bool player) {
    std::cout << "Enter the x coordinate (vertical V):" << std::endl;
    std::cin >> x;

    std::cout << "Enter the y coordinate (horizontal >):" << std::endl;
    std::cin >> y;
    // 1. cell should be empty; 2. x has to be relevant; 3. y has to be relevant.
    if ((array[x][y] == gameSymbols::empty) && (0 <= x < Rows) && (0 <= y < Columns)) {
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

bool playerMakeStep(gameSymbols** array, int Rows, int Columns, bool player) {

    if (player == 1) {
        std::cout << "1st player make step: " << std::endl;
        // true = step was successfully finished; false = same player needs to make another step:

        if (gameSymbolChanged(array, Rows, Columns, player)) {
            player = !player;
            stepCounter++;
        }
        else { player = player;
        }
    }

    else if (player == 0) {
        std::cout << "2nd player make step: " << std::endl;
        // true = step was successfully finished; false = same player needs to make another step:

        if (gameSymbolChanged(array, Rows, Columns, player)) {
            player = !player;
            stepCounter++;
        }
        else { player = player;
        }
    }
    return player;
}

bool vectorCheck(gameSymbols* vector, int Size) {
    // take the first element of the vector and looking for the end:
    gameSymbols temp = vector[0];
    int counter = 0;

    std::cout << "This is a vector : ";
    for (int i = 0; i < Size; i++) {
        std::cout << vector[i];

        if ((vector[i] != gameSymbols::empty) && (vector[i] == temp)) {
            counter ++;
        }

    }
    if (counter == Size){
        std::cout << "all elements are equal, " << "counter = " << counter << std::endl;
        return true;
    }
    else {
        std::cout << "not all elements are equal" << "counter = " << counter << std::endl;
        return false;
    }
}

bool playerVictoryCheck(gameSymbols** array, int Rows, int Columns, int x_internal, int y_internal, int vectorSize) {
    // creating array:
    gameSymbols* checkingArray = new gameSymbols[vectorSize]; // creating 1D array of elements to check

    // checking the vertical vector from point[x_internal][y_internal]:
    {
        std::cout << "vertical: ";
        for (int i = 0; i < Rows; i++) {
            checkingArray[i] = array[i][y_internal];
            std::cout << printSymbol(checkingArray[i]);
        }
        std::cout << std::endl;
        // for debugging:
        // std::cout << "main_flag 1 = " << vectorCheck(checkingArray, vectorSize) << std::endl;
        // std::cout << "vectorSize = " << vectorSize << std::endl;
        if (vectorCheck(checkingArray, vectorSize)){
            std::cout << "Player " << !playerOrder << "win" << std::endl;
            return true;
        }
    };

    // horizontal check:
    {
        std::cout << "horizontal: ";
        for (int j = 0; j < Columns; j++) {
            checkingArray[j] = array[x_internal][j];
            std::cout << printSymbol(checkingArray[j]);
        }
        std::cout << std::endl;
        // for debugging:
        //std::cout << "main_flag 2 = " << vectorCheck(checkingArray, vectorSize) << std::endl;
        //std::cout << "vectorSize = " << vectorSize << std::endl;
        if (vectorCheck(checkingArray, vectorSize)){
            std::cout << "Player " << !playerOrder << "win" << std::endl;
            return true;
        }
    };

    // diagonal check from the top left to the bottom right: (diagonalTL2BR)
    {
        // in some cases diagonal less than vector to win in this case we do not check it
        int elementCounting = 0;
        std::cout << "diagonal from top left to bottom right: ";

        // create operators:
        int x_check = x_internal; int y_check = y_internal;

        // x and y both decrease:
        while ((x_check != -1) && (y_check != -1)) {
            std::cout << printSymbol(array[x_check][y_check]);
            x_check--; y_check--; elementCounting++;
        }

        // reset operators:
        x_check = x_internal+1; y_check = y_internal+1;

        // x and y both increase:
        while ((x_check < Rows) && (y_check < Columns)) {
            std::cout << printSymbol(array[x_check][y_check]);
            x_check++; y_check++; elementCounting++;
        }
        std::cout << std::endl;

        // записать в массив:
        if (elementCounting >= vectorSize) {
            for (int k = 0; k < vectorSize; k++) {

                int x_check = x_internal; int y_check = y_internal;
                while ((x_check != -1) && (y_check != -1)) {
                    checkingArray[k] = array[x_check][y_check];
                    x_check--; y_check--; k++;
                }

                x_check = x_internal + 1; y_check = y_internal + 1;
                while ((x_check < Rows) && (y_check < Columns)) {
                    checkingArray[k] = array[x_check][y_check];
                    x_check++; y_check++; k++;
                }
                //std::cout << std::endl;
            }
        }
        // for debugging:
        //std::cout << "main_flag 3 = " << vectorCheck(checkingArray, vectorSize) << std::endl;
        //std::cout << "vectorSize = " << vectorSize << std::endl;
        if (vectorCheck(checkingArray, vectorSize)){
            std::cout << "Player " << !playerOrder << "win" << std::endl;
            return true;
        }
    };

    // diagonal check from the bottom left to the top right: (diagonalBL2TR)
    {
        // in some cases diagonal less than vector to win in this case we do not check it
        int elementCounting = 0;
        std::cout << "diagonal from the bottom left to the top right: ";

        // reset operators:
        int x_check = x_internal; int y_check = y_internal;

        while ((x_check < Rows) && (y_check != -1)) {
            std::cout << printSymbol(array[x_check][y_check]);
            x_check++; y_check--; elementCounting++;
        }

        x_check = x_internal-1; y_check = y_internal+1;

        while ((x_check != -1) && (y_check < Columns)) {
            std::cout << printSymbol(array[x_check][y_check]);
            x_check--; y_check++; elementCounting++;
        }
        std::cout << std::endl;

        // записать в массив:
        if (elementCounting >= vectorSize) {
            for (int k = 0; k < vectorSize; k++) {

                int x_check = x_internal; int y_check = y_internal;

                while ((x_check < Rows) && (y_check != -1)) {
                    checkingArray[k] = array[x_check][y_check];

                    x_check++; y_check--; k++;
                }

                // reset operators:
                x_check = x_internal - 1; y_check = y_internal + 1;

                while ((x_check != -1) && (y_check < Columns)) {
                    checkingArray[k] = array[x_check][y_check];
                    x_check--; y_check++; k++;
                }
                //std::cout << std::endl;
            }
        }
        // for debugging
        //std::cout << "main_flag 4 = " << vectorCheck(checkingArray, vectorSize) << std::endl;
        //std::cout << "vectorSize = " << vectorSize << std::endl;
        if (vectorCheck(checkingArray, vectorSize)){
            std::cout << "Player " << !playerOrder << "win" << std::endl;
            return true;
        }
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

    std::cout << "Enter the size of the sequence enough for victory " << std::endl;
    vectorSize = ((static_cast<int>(vectorSize) == vectorSize) && (vectorSize < fieldSize)) ? vectorSize : 3;
    std::cin >> vectorSize;

    gameSymbols ** gameField =  fieldGeneration(fieldSize, fieldSize);
    gameFieldUpdate(gameField, fieldSize, fieldSize); // just ofr demonstration initial field

    std::cout << "Show must go on !!! " << std::endl;


    // 2nd Block - Game:
    while ((stepCounter < fieldSize * fieldSize) && (victoryFlg == false)) {

        playerOrder = playerMakeStep(gameField, fieldSize, fieldSize, playerOrder);
        gameFieldUpdate(gameField, fieldSize, fieldSize);

        if (stepCounter >= (vectorSize * 2 - 1)) { // <<--- there is no reason to check it before
            victoryFlg = playerVictoryCheck(gameField, fieldSize, fieldSize, x, y, vectorSize);
        }

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
