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

5. ** Написать функцию, которой передается не пустой одномерный целочисленный массив,
она должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны.
Примеры:
checkBalance([1, 1, 1, || 2, 1]) → true,
checkBalance ([2, 1, 1, 2, 1]) → false,
checkBalance ([10, || 1, 2, 3, 4]) → true.
Абстрактная граница показана символами ||, эти символы в массив не входят.

*/

#include <iostream>
#include <chrono>
#include <random>
#include <stdlib.h> 
#include <typeinfo>

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

// Block of variables:

// for task 1:
const int arr_t1_size = 8;
double arr_t1[arr_t1_size] = { 12.0, 24.10, 14.0, 123.324, 43.5, 13.7, 45.98, 45.89 };
double* arr_t1_ptr = &arr_t1[0];

// for task2:
const int arr_t2_size = 8;
int arr_t2[arr_t2_size] = { 1, 0, 0, 1, 1, 1, 1, 0 };
int* arr_t2_ptr = &arr_t2[0];

// for task 4:
const int arr_t4_size = 10;

// for task 5:
const int arr_t5_size = 5;

// Block of functions:
bool print_array_direct(double arr_fun[], const int arr_size) {
    /*
    Функция выводит массив double чисел на экран.
    Параметры функции это сам массив и его размер.
    Если массив передан в функцию и успешно выведен на экран, то функция возвращает true.
    В случае ошибки - false
    */

    if (arr_fun == nullptr) {
        cout << "pointer is empty ";
        return false;
    }

    if (arr_size == NULL) {
        cout << "array is empty ";
        return false;
    }

    for (int i = 0; i < arr_size; i++) {
        cout << arr_fun[i] << ' ';
    }
    cout << endl;
    return true;
}

bool print_array_by_pointer(double* arr_ptr, const int arr_size) {
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

    if (arr_size == NULL) {
        cout << "array is empty ";
        return false;
    }

    for (int i = 0; i < arr_size; i++) {
        cout << *(arr_ptr + i) << ' ';
    };
    cout << endl;
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
        print_array_direct(arr_t1, arr_t1_size);
    }

    if (flg == 'B') {
        print_array_by_pointer(arr_t1_ptr, arr_t1_size);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    return duration.count();

}

// Redefine the function of array printing (the faster one). It allows to print int arrays also
bool print_array_by_pointer(int* arr_ptr, const int arr_size) {
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

    if (arr_size == NULL) {
        cout << "array is empty ";
        return false;
    }

    for (int i = 0; i < arr_size; i++) {
        cout << *(arr_ptr + i) << ' ';
    };
    cout << endl;
    return true;
}

// Function for task3:
void predefine_filling_arr(int* arr_ptr, const int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        *(arr_ptr + i) = 1 + 3 * i;
    }

}

// Functions for task4:
void random_array_builder(double* arr_ptr, const int arr_size, int32_t min_element, int32_t max_element) {
    for (int i = 0; i < arr_size; i++) {
        *(arr_ptr + i) = getRandomNum(min_element, max_element);
    }
}

bool array_cicle_shift(double arr[], int shift) {
    int buffer;

    if (shift > 0) {
        for (int i = 0; i < shift; i++) {
            // step 1. taking the last element of the array to the buffer:
            buffer = arr[arr_t4_size - 1];
            //cout << "buffer = " << buffer << endl;

            // step 2. shifting array to the right  >> on 1 position (HINT: Starts from the previous to the last element)
            for (int j = (arr_t4_size - 2); j > -1; j--) {
                //cout << "j = " << j << endl;
                arr[j + 1] = arr[j];
            }

            // step3. insert from the buffer to the 1st eleemnt of array
            arr[0] = buffer;

            // result:
            print_array_by_pointer(&arr[0], arr_t4_size);
        }
        return true;
    }

    else if (shift < 0) {
        for (int i = 0; i > shift; i--) {
            // step 1. Taking the 1st element to the buffer:
            buffer = arr[0];
            //cout << "buffer = " << buffer << endl;

            // step 2. Shifting the array to the one position left:
            for (int j = 0; j < arr_t4_size - 1; j++) {
                //cout << "j = " << j << endl;
                arr[j] = arr[j + 1];
            }

            // step 3. Insert from the buffer to the last element of the array:
            arr[arr_t4_size - 1] = buffer;

            // result: 
            print_array_by_pointer(&arr[0], arr_t4_size);


        }
        return true;
    }

    else {
        cout << "shift = 0; " << "array do not changed" << endl;
        print_array_by_pointer(&arr[0], arr_t4_size);
        return false;
    }

}

// Function for task 5:
double arr_interval_sum(double arr[], int id_first, int id_last) {
    double sum = 0;

    for (int i = id_first; i <= id_last; i++) {
        sum = sum + arr[i];
        //cout << "sum = " << sum << endl;
    }

    return sum;
}

bool check_balance(double arr[]) {
    // step 1. Split the pop
    int element_of_boarder = arr_t5_size / 2;
    //cout << "element_of_boarder = " << element_of_boarder << endl;

    // step 2. Look which area is bigger (L = left) or (R = right)
    double L_sum, R_sum;
    bool L_flg = false, R_flg = false;   
   
    // step 3. Check
    do {
        L_sum = arr_interval_sum(arr, 0, element_of_boarder - 1);
        R_sum = arr_interval_sum(arr, element_of_boarder, arr_t5_size - 1);
        //cout << "L_sum = " << L_sum << ' ' << "R_sum = " << R_sum << endl;
        //cout << "L_flg = " << L_flg << ' ' << "R_flg = " << R_flg << endl;

        if (L_sum == R_sum) {
            cout << endl << "<--- TRUE";
            return true;
        }
            
        if (L_sum < R_sum) {
            //cout << endl << "L -->" << " element_of_boarder = " << element_of_boarder << endl;
            L_flg = true;
            element_of_boarder = element_of_boarder + 1;
        }
        if (L_sum > R_sum){
            //cout << endl << "R -->" << " element_of_boarder = " << element_of_boarder << endl;
            R_flg = true;
            element_of_boarder = element_of_boarder - 1;
        }  
    } while ( ( (element_of_boarder > 0) && (element_of_boarder != arr_t5_size) ) && ((L_flg && R_flg) == false));
    
    cout << "<--- FALSE" << endl;
    return false;
}

int main() {
    // task1:  
    {
        //variant A: put whole array inside the function: 
        cout << "printing array takes " << duration_of_function_execution('A') << "micro seconds" << endl;

        //variant B: pointer to the fist element of the array:
        cout << "printing array takes " << duration_of_function_execution('B') << "micro seconds" << endl;
        cout << endl;
    }

    // task 2: 
    {
        cout << "initial array: ";
        print_array_by_pointer(arr_t2_ptr, arr_t2_size);

        for (int i = 0; i < arr_t2_size; i++) {
            if (*(arr_t2_ptr + i) == 0) {
                *(arr_t2_ptr + i) = 1;
            }
            else {
                *(arr_t2_ptr + i) = 0;
            }
        };

        cout << "array after transformation: ";
        print_array_by_pointer(arr_t2_ptr, arr_t2_size);
        cout << endl;
    }

    // task 3:
    {
        int arr_t3[8] = {};

        cout << "t3 array before: ";
        print_array_by_pointer(&arr_t3[0], 8);

        predefine_filling_arr(&arr_t3[0], 8);


        cout << "t3 array after: ";
        print_array_by_pointer(&arr_t3[0], 8);
        cout << endl;
    }

    // task 4:
    
    {
        // creating array:
        double arr_t4[arr_t4_size] = {};
        int shift_n;

        random_array_builder(&arr_t4[0], arr_t4_size, 1, 12);

        cout << "this is array to shift: " << endl;
        print_array_by_pointer(&arr_t4[0], arr_t4_size);

        // shifting array:
        cout  << "Please enter how many times (integer number) & in which direction (depends of sign) you want to shift the array: ";
        cin >> shift_n;
        array_cicle_shift(arr_t4, shift_n);
    }
    

    // task 5:
    {
        // creating array:
        //double arr_t5[arr_t5_size] = {1, 1, 1, 1, 9};
        double arr_t5[arr_t5_size] = {};
        random_array_builder(&arr_t5[0], arr_t5_size, 2, 42);
        cout << "this is array to balance checking: " << endl;
        print_array_by_pointer(&arr_t5[0], arr_t5_size);

        // Balance checking:
        check_balance(arr_t5);
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
https://www.andreyolegovich.ru/code/cpp/typeid.php - explanation how to return the type of the variable
https://www.cplusplus.com/doc/tutorial/operators/ - operators in C++ 
*/
