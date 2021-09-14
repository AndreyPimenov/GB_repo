// HW3:
/*
1. Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), 
если да – вывести строку "true", в противном случае – "false";

2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, 
объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти.Иначе "false".

3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. 
Например: "Your numbers: 1 3 5 7 9 11 13 …".Для решения используйте любой С++ цикл.

4. Со звёздочкой.Написать программу, проверяющую, является ли некоторое число - простым.
Простое число — это целое положительное число, которое делится без остатка только на единицу и себя само.

5. Со звёздочкой.Пользователь вводит с клавиатуры число(год) : от 1 до 3000. 
Написать программу, которая определяет является ли этот год високосным.
Каждый 4 - й год является високосным, кроме каждого 100 - го, при этом каждый 400 - й – високосный.
Вывести результаты работы программы в консоль.
*/

#include <iostream>
using namespace std;

const int const1 = rand()%10 +5;
const int const2 = rand()%10 +5;

int num4, num5; 

int main() {
    // task 1
    {
        int num1, num2;
        cout << "Input the 1st number: " << endl;
        cin >>  num1;
        cout << "Input the 2nd one: " << endl;
        cin >> num2;
        
        if ((num1 + num2) >= 10 && (num1 + num2) <= 20) {
            cout << "true";
        }
        else {
            cout << "false";
        }
    }
    
    // task 2
    {
        if ((const1 == 10) || (const2 == 10) || ((const1 + const2) == 10)) {
            cout << "true";
            cout << const1 << ' ' << const2;
        }
        else {
            cout << "false";
            cout << const1 << ' ' << const2;
        }

    }

    // task 3
    {
        cout << "Your numbers: ";
       
        for (int i = 1; i < 50; i++) {
            if (i % 2 == 1) {
                cout << i << "; ";
            }
        };
    }

    // task 4
    {
        cout << "Input number " << endl;
        cin >> num4;
    // 1st algorithm (first idea):
    if (num4 > 0) {
        for (int i = 1; num4-1; i+2) {
            if (num4 % i == 0) {
                cout << "this is not a simple number!" << endl;
                break;
            }
            else {
                cout << "this is a simple number!" << endl;
                break;
            }
        }
    }
    else {
        cout << "please enter positive number next time";
    }

    // 2nd algorithm:
    {
        for (int i = 1; i <= sqrt(num4); i+2) {
            if (num4 % i == 0) {
                cout << "this is not a simple number!" << endl;
                break;
            }
            else {
                cout << "this is a simple number!" << endl;
                break;
            }
        }
    };
    // It could be realisen on: 
    // Eratosphen algorithm = https://habr.com/ru/post/91112/ 
    // Ferma algorithm = https://habr.com/ru/post/205318/
    }
    
    // task 5
    {
        cout << "Please enter the year from 1 to 3000, for checking: " << endl;
        cin >> num5;
        if (((num5 % 4 == 0)&&(num5 %100 != 0)) || ((num5 % 400 == 0) && (num5 %100 == 0))) {
            cout << "this is a leap year"; 
        }
        else {
            cout << "this year has 365 days inside"; 
        }

    }
}

