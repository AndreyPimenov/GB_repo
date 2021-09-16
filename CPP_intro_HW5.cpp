#include <iostream>
#include <chrono>
#include <random>
#include <stdlib.h>


using namespace std;
using namespace std::chrono;

// Learning point - pointers and references:
/*
int x; // create an object
int *y = &x; // the adress of x in y. &x - returns pointer
int z = *y; // returns the object (reference) 
int d = 40; 

void tryToChange( int a, int *pB, int &rC){ // три способа передачи параметра в функцию 
    a = 1000;
    *pB = 2000;
    rC = 3000;
    d = 4000; // изменится как глобальная переменная
}

int main(){
    int a =10, b =20, c = 30; 
    tryToChange(a, &b, c);
    cout << a << ' ' << b << ' ' << c << ' ' << d << ' '; // 10, 2000, 3000, 4000

    return 0; 
}

*/

// Learning point - get random number:
int32_t getRandomNum(int32_t min, int32_t max) {
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

// HW5:
/*
1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. 
Вызвать эту функцию из main.

2. Задать целочисленный массив, состоящий из элементов 0 и 1. 
Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. 
Выводить на экран массив до изменений и после.

3. Задать пустой целочисленный массив размером 8. 
Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.

4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), 
при этом метод должен циклически сместить все элементы массива на n позиций.

5. ** Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в массиве есть место, 
в котором сумма левой и правой части массива равны. 
Примеры: 
checkBalance([1, 1, 1, || 2, 1]) → true, 
checkBalance ([2, 1, 1, 2, 1]) → false, 
checkBalance ([10, || 1, 2, 3, 4]) → true. 
Абстрактная граница показана символами ||, эти символы в массив не входят.

*/

// Block of variables:
const int test_ar_size = 8;
double test_array[test_ar_size] = { 12.0, 24.10, 14.0, 123.324, 43.5, 13.7, 45.98, 45.89 };
double* arr_ptr = &test_array[0];


// Blcok of functions:
bool print_array_direct(double arr_fun [], const int ar_size) {
    /* 
    Функция выводит массив double чисел на экран.
    Параметры функции это сам массив и его размер.
    Если массив передан в функцию и успешно выведен на экран, то функция возвращает true. 
    В случае ошибки - false
    */

    if (arr_fun == nullptr){
        cout << "pointer is empty ";
        return false;
    }

    if (ar_size == NULL) {
        cout << "array is empty ";
        return false;
    }
        
    for (int i = 0; i < ar_size; i++){
        cout << arr_fun[i] << ' ';
    }
    return true;
}

bool print_array_pointer(double* arr_ptr, const int ar_size) {
    /*
    Функция принимает указатель на первый элемент массива.
    и выводит на экран остальные элементы массива сдвигая адрес на одну позицию 
    Если массив успешно выведен на экран, то функция возвращает true.
    В случае ошибки - false
    */

    if (arr_ptr == nullptr) {
        cout << "pointer is empty ";
        return false;
    }
        
    if (ar_size == NULL) {
        cout << "array is empty ";
        return false;
    }
        
    for (int i = 0; i < ar_size; i++) {
        cout << *(arr_ptr + i) << ' ';
    };
    return true;
}

double duration_of_function_execution(char flg) {
    /*
    Функция засекает время на печать массива
    Входной параметр: флаг - от него зависит какую функцию печати массивыа выберем (по указателю или по значению)
    */


    auto start = high_resolution_clock::now();

    // call fucntion:
    if (flg == 'A') { 
        print_array_direct(test_array, test_ar_size); 
    }

    if (flg == 'B') {
        print_array_pointer(arr_ptr, test_ar_size); 
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    return duration.count(); 

}

int main() {
    // task1:  
    {
        // variant A: put whole array inside the function: 
        //print_array_dir(test_array, test_ar_size);
        cout << "printing array takes " << duration_of_function_execution('A') << "micro seconds" << endl; 
        
        //  variant B: pointer to the fist element of the array:
        //print_array_ptr(arr_ptr, test_ar_size);
        cout << "printing array takes " << duration_of_function_execution('B') << "micro seconds" << endl;
        
    }
    

    // task 2: 
    {
        
        



    }

    return 0;
}

// PS Useful resources:
/*
https://purecodecpp.com/archives/1188 - references in C++ part I
https://purecodecpp.com/archives/2286 - references in C++ part II
https://habr.com/ru/post/251091/ - deeper understanding of pointers & references
https://ravesli.com/urok-91-tsikl-foreach/ - for each cicle in C++
https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ - using chrono library 


*/
