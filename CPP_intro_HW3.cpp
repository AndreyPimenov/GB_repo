#include <iostream>
using namespace std;

/*
1. Написать программу, вычисляющую выражение a * (b + (c / d)) и выводящую результат с плавающей точкой, где a, b, c, d – целочисленные константы. 
Используйте static_cast или СStyle cast к float чтобы выполнить точное деление.

2. Дано целое число. Если оно меньше или равно 21, то выведите на экран разницу между этим числом и числом 21. 
Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21. 
При выполнении задания следует использовать тернарный оператор (?:).

3.* Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на значения внутри массива и 
при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба [1][1][1].

4. ** Написать программу, вычисляющую выражение из первого задания, 
а переменные для неё объявлены и инициализировать в другом cpp файле. Используйте extern.
*/

extern int a4, b4, c4, d4;

int main()
{
    // Learning point increemnt (prefix vs postfix), bit operations, etc
    /*{
        int a = 10, b = 20;
        a++; // a = 11
        ++a; // a = 12
        b = a++; // b = 12, a = 13
        b = ++a; // a = 14, b = 14
        cout << a << endl;
        cout << b << endl;

        // bit operations: 
        //  & - OR
        //  | - AND
        //  ~ - NOT
        //  ^ - XOR
        // << - shift to the left
        // >> - shift to the right
    }
    */

    // task 1
    
    {
        int a, b, c, d;
        cout << "input int a : " << endl;
        cin >> a;
        cout << "input int b : " << endl;
        cin >> b;
        cout << "input int c : " << endl;
        cin >> c;
        cout << "input int d : " << endl;
        cin >> d;

        float preliminary_answer = static_cast <float> (c) / d + b;
    
        cout << preliminary_answer * a;

    }
    

    // task 2
    
    {
        int n;
        cout << "enter the integer number: " << endl;
        cin >> n;
        
        // solution if - else:
        if (n <= 21) {
            cout << abs(21 - n) << endl;
        }
        else {
            cout << 2 * abs(n - 21) << endl;
        }

        // solution with ternal operator:
        int answer = (n <= 21) ? abs(21 - n) : 2 * abs(n - 21);
        cout << answer << endl;

    }
    

    // task 3
    
    {
        int arr[3][3][3] = { {{1,2,3},{4,5,6},{7,8,9}}, {{11,12,13},{14,15,16},{17,18,19}}, {{21,22,23},{24,25,26},{27,28,29}} };
        int* ptr;
        ptr = &arr[1][1][1]; // creating a reference to element of the array

        int y = *ptr; 
        cout << y << endl; 
  
    }

    // task 4
    {
        float preliminary_answer_ext = static_cast <float> (c4) / d4 + b4;

        cout << preliminary_answer_ext * a4;

    }
    
}
