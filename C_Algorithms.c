// C_working_area.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <iostream>
#include <stdio.h>
#include <stdlib.h> // для перехода на русский язык

int main()
{
    
    int limit;
    printf("Enter the number: ");
    scanf("%d", &limit);

    
    int last_simple = 0; // если last_simple == limit, то введеное число -  простое, иначе составное; 
    
    int sqr_lim;
    bool is_prime[1001];
    int x2, y2;
    int i, j;
    int n;

    // Инициализация решета
    sqr_lim = (int)sqrt((long double)limit);
    for (i = 0; i <= limit; ++i)
        is_prime[i] = false;
    is_prime[2] = true;
    is_prime[3] = true;

    // Предположительно простые — это целые с нечётным числом
    // представлений в данных квадратных формах.
    // x2 и y2 — это квадраты i и j.
    x2 = 0;
    for (i = 1; i <= sqr_lim; ++i) {
        x2 += 2 * i - 1;
        y2 = 0;
        for (j = 1; j <= sqr_lim; ++j) {
            // отсеить четные
            y2 += 2 * j - 1;
            
            // n = 4*x2 + y2
            // проверка 1, 13, 17, 29, 37, 41, 49 или 53, имеют остаток от деления на 4, равный 1. 
            // Эти числа являются простыми тогда и только тогда, когда количество решений уравнения 4x2 + y2 = n нечётно 
            // и само число не кратно никакому квадрату простого числа
            n = 4 * x2 + y2;
            if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
                is_prime[n] = !is_prime[n];

            // проверка 7, 19, 31, или 43, имеют остаток от деления на 6, равный 1. Эти числа являются простыми тогда и только тогда, 
            // когда количество решений уравнения 3x2 + y2 = n нечётно и само число не кратно никакому квадрату простого
            n -= x2; // n = 3 * x2 + y2; 

            if ((n <= limit) && (n % 12 == 7))
                is_prime[n] = !is_prime[n];

            // проверка 11, 23, 47, или 59, имеют остаток от деления на 12, равный 11. Эти числа являются простыми тогда и только тогда, 
            // когда количество решений уравнения 3x2 − y2 = n (для x > y) нечётно и само число n не кратно никакому квадрату простого.
            n -= 2 * y2; // n = 3 * x2 - y2;
            if ((i > j) && (n <= limit) && (n % 12 == 11))
                is_prime[n] = !is_prime[n];
        }
    }

    // Отсеиваем кратные квадратам простых чисел в интервале [5, sqrt(limit)].
    // (основной этап не может их отсеять)
    for (i = 5; i <= sqr_lim; ++i) {
        if (is_prime[i]) {
            n = i * i;
            for (j = n; j <= limit; j += n)
                is_prime[j] = false;
        }
    }

    // Вывод списка простых чисел в консоль.
    /*
    printf("2, 3, 5");
    for (i = 6; i <= limit; ++i) {  // добавлена проверка делимости на 3 и 5. В оригинальной версии алгоритма потребности в ней нет.
        if ((is_prime[i]) && (i % 3 != 0) && (i % 5 != 0))
            //printf(", %d", i);
    }
    */

    // Дописанный мной блок кода:
    if ((limit == 2) or (limit == 3) or (limit == 5)) {
        printf("This is simple number");
    }
    else { // запускаем проверку:
        for (i = 6; i <= limit; ++i) {  // добавлена проверка делимости на 3 и 5. В оригинальной версии алгоритма потребности в ней нет.
            if ((is_prime[i]) && (i % 3 != 0) && (i % 5 != 0))
                last_simple = i;
        }

        if (last_simple == limit) {
            printf("This is simple number");
        }
        else {
            printf("This is not a simple number");
        }
    }
    

}
