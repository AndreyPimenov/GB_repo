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
            ptrArr[i] = pow(2,i); 
            cout << ptrArr[i] << endl;
        }
       
        // empty space of the array: 
        delete[] ptrArr;
        ptrArr = nullptr;
    }
    else {
        std::cout << "Error n in not positive integer number";
    }
}

int main() {

    //task1
    {
        int n = 0;
        cout << "Enter the size of the array = ";
        cin >> n;
        createArrayTask1(n);
    }


    // task 2
    {

    }

    // task 3
    {
        string text1 = "Damien Jr. Marley (= One Loaf of Bread ;) :)  Yeah!! Christ feed the multitude wid only one loaf of bread";
        string text2 = "Rasta works a manifest an it a blossom an a bloom, Nature always run it course the tide is rising wit the moon, ";
        cout << "There are the size of strings: " << size(text1) << " & " << size(text2) << endl;

    }

    // task 4
    {
        
           
    }

    // task 5
    {


    }
    
    

    


    return 0;
}
