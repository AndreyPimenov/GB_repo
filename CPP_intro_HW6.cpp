// HW6:
/*
1. Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 …
Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции.

2. Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.

3. Написать программу, которая создаст два текстовых файла (*.txt),
примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым).
Имена файлов запросить у пользователя.

4. * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).

5. * Написать программу, которая проверяет присутствует ли указанное пользователем
при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
Используем функцию find которая есть в строках std::string.
*/

#include <iostream>
#include <random>
#include <string>
#include <math.h>
#include <fstream>
#include <chrono>

using namespace std;

void createArrayTask1(int n) {
    /*
    n - the size of the array
    */
    int* ptrArr; // pointer to Array
    if (n > 0) {
        // creating an array:
        ptrArr = new (std::nothrow) int[n];
        ptrArr[0] = 1;

        // filling it with 2 in the power of i++
        for (int i = 0; i < n; i++) {
            ptrArr[i] = pow(2, i);
            std::cout << ptrArr[i] << " ";
        }

        std::cout << endl;
        // empty space of the array: 
        delete[] ptrArr;
        ptrArr = nullptr;
    }
    else {
        std::cout << "Error n in not positive integer number";
    }
}

// Learning point - get random number (from previous class):
int32_t getRandomNum(int32_t min, int32_t max) {
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void createMatrix4X4() {
    int32_t min_num = 0;
    int32_t max_num = 0;

    // Diapasone of random number:
    std::cout << "Please, enter the minimum number on diapasone: ";
    std::cin >> min_num;
    std::cout << "\n" << "Please, enter the minimum number on diapasone: ";
    std::cin >> max_num;

    // creating array: 
    int** ppArr = new int* [4];
    for (int i = 0; i < 4; i++) {
        ppArr[i] = new int[4];
        //cout << "i = " << i << " ";
    }

    // filling this array with random numbers:
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ppArr[i][j] = getRandomNum(min_num, max_num);
        }
    }


    // printing this array:
    std::cout << "This is a matrix 4x4: " << endl;

    for (int i = 0; i < 4; i++) {
        std::cout << endl;
        for (int j = 0; j < 4; j++) {
            // cout << "ppArr[" << i << "][" << j << "] = " << ppArr[i][j] << endl; - 1st variant
            std::cout << ppArr[i][j] << " ";
        }
    }

    std::cout << "\n";
    // emptying the space:
    for (int i = 0; i < 4; i++) {
        delete ppArr[i];
        //cout << "i = " << i << " ";
    }
    delete[] ppArr;
}

void fillingTextFile(string fileName, string text) {

    // creating the file:
    ofstream file(fileName + ".txt");

    // openning the file:
    if (!file) {
        std::cout << "Some problems to writing in file" << std::endl;
    }

    // writing the string to the file
    file << text << endl;

}

void addingTextFiles() {
    int n = 0; // number of files to sum up
    string name; // buffer for name of user files
    string buffer; // buffer for content of user files
    string resultFile = "resultFile";
    string resultString;
    std::cout << "Please, enter the number of files to sum up: " << endl;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Please, enter just the name of text file (without .txt): " << endl;
        cin >> name;
        // forming the resulting string:
        ifstream fin(name + ".txt");
        if (fin.is_open()) {
            while (!fin.eof()) {
                getline(fin, buffer);
                resultString = resultString + " " + buffer;
                //std::cout << buffer << endl;
            }
            fin.close();
        }
    }

    fillingTextFile(resultFile, resultString);
}

void lookingForWordInText(string wordToFind, string fileName) {
    string buffer; // buffer for content of user files

    // line by line looking the input word or sentence (string) 
    ifstream fin(fileName);
    if (fin.is_open()) {
        while (!fin.eof()) {
            string curentOne;

            fin >> curentOne;
            
            if (wordToFind == curentOne) {
                std::cout << "currentOne = " << curentOne << " " << "wordToFind = " << wordToFind << endl;
                break;
            }
            else {
                continue; // std::cout << "Not found\n";
            }
        }
        fin.close();
    }
}

int main() {

    //task1
    {
        int n = 0;
        std::cout << "Enter the size of the array = ";
        std::cin >> n;

        createArrayTask1(n);
    }

    // task 2
    {
        createMatrix4X4();
    }

    // task 3
    {
        string name1, name2;
        string text1 = "Damien Jr. Marley (= One Loaf of Bread ;) :)  Yeah!! Christ feed the multitude wid only one loaf of bread";
        string text2 = "Rasta works a manifest an it a blossom an a bloom, Nature always run it course the tide is rising wit the moon, ";
        std::cout << "There are the size of strings: " << size(text1) << " & " << size(text2) << std::endl;

        // 1st:
        std::cout << "Input the name for the file" << std::endl;
        std::cin >> name1;
        fillingTextFile(name1, text1);

        //2nd:
        std::cout << "Input the name for the file" << std::endl;
        std::cin >> name2;
        fillingTextFile(name2, text2);

    }

    // task 4
    {
        addingTextFiles();
    }

    // task 5
    {
        string wordToFind;
        string fileName = "resultFile.txt";

        std::cout << "Please enter the word to find: " << endl;
        std::cin >> wordToFind;

        lookingForWordInText(wordToFind,fileName);
    }

    return 0;
}

// PS - Usefull links:
// https://ravesli.com/urok-212-bazovyj-fajlovyj-vvod-vyvod/ = working with files 
// https://www.cplusplus.com/reference/string/string/ = Oficial Documents for string 
// https://www.cyberforum.ru/cpp-beginners/thread806146.html = helps for 5th task of the problem set 
