#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// for checkmate problem:
#define HEIGHT 8
#define WIDTH 8 
#define KING 1

int board[HEIGHT][WIDTH]; 

void annull() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j ) {
            board[i][j] = 0;
        }    
    }
}

void printBoard() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%3d", " ", board[i][j]);
        }
        printf("\n");
    }

}


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
        if ((num_dec % 2) == 0) {
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

// a in power of b: recursive
int power_a_in_b(int a, int b) {
    if (b != 0) {
        return (a * power_a_in_b(a, b - 1));
    }
}

// a in power of b: recursive
int power_a_in_b_odd_even(int a, int b) {
    if (b != 0) {
        if ( (b % 2) == 0)
        {
            return power_a_in_b_odd_even(a*a, b/2);
        }

        else {
            return (a * power_a_in_b_odd_even(a, b - 1));
        }
    }
    else {
        return 1;
    }
     
}


int main()
{
    int number;
    int a;
    int b;
    int answer;
    printf("Enter the number: ");
    scanf("%d", &number);

    // Task 0:
    /*
    /b = factorial(a);
    //printf("%d", b);

    //void numsys_ten_to_two_iterative(a);

    //rec(a);
    */


    // Lesson 4. Problem 1: use recursion to change numeric system from 10 to 2:
    numsys_ten_two(number);
    printf("\n");

    // Lesson 4.a) Problem 2: use recursion to a ^ b 
    printf("Enter the number a: ");
    scanf("%d", &a);
    printf("Enter the number b: ");
    scanf("%d", &b);

    answer = power_a_in_b(a, b);
    printf("%d", answer);
    printf("\n");

    // Lesson 4.a) Problem 2: use recursion to a ^ b 
    answer = power_a_in_b_odd_even(a, b);
    printf("%d", answer);
}

