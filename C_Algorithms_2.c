#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// recursion exp 1: factorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return factorial(n - 1) * n;
    }
}

// recursion exp 2:
void rec(int a) {
    printf("%5d", a); // выведет от большого к меньшему
    if (a > 0)
        rec(a - 1);
    // printf("%5d", a); // выведет от меньшего к большему
}

// transform numeric system from 10 to 2: iterative
void numsys_ten_to_two_iterative(int num_dec) {
    char num_bin[] = "";
    while (num_dec != 0) {
        if ((num_dec  % 2) == 0) {
            num_dec = num_dec / 2;
            printf("%d", 0);
        }
        else {
            num_dec = (num_dec - 1) / 2;
            printf("%d", 1);
        }
    }
}

// transform numeric system from 10 to 2: recursive
void numsys_ten_two(int num_dec) {
    
    if (num_dec > 1) {
        numsys_ten_two(num_dec / 2);
    }
    printf("%5d", num_dec % 2);
}




int main()
{
    int a;
    int b;
    printf("Enter the number a: ");
    scanf("%d", &a);
    printf("Enter the number b: ");
    scanf("%d", &b);

    // Task 0:
    /*
    /b = factorial(a);
    //printf("%d", b);

    //void numsys_ten_to_two_iterative(a);

    //rec(a);
    */
   

    // Lesson 4. Problem 1: use recursion to change numeric system from 10 to 2:
    numsys_ten_two(a);

    // Lesson 4. Problem 2: use recursion to a ^ b 





}
