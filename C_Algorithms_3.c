#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// _____________________PROBLEM N3 (my attempt):
#define HEIGHT 8
#define WIDTH 8 
#define KING 1

int board[HEIGHT][WIDTH]; 
int x_king, y_king, x_goal, y_goal;

void annull() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j ) {
            board[i][j] = 0;
        }    
    }
}

void print_board() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }

}

void put_obstacles(int num_obst) {
    int x_coord; int y_coord;
    for (int i = 0; i < num_obst; ++i) {
        printf("Enter X (from up to down) coordinate (from 0 to 7) of the obstacle");
        scanf("%d", &x_coord);
        printf("Enter Y (from left to right) coordinate (from 0 to 7) of the obstacle");
        scanf("%d", &y_coord);
        board[x_coord][y_coord] = -1;
    }
}

void put_the_king() {
    int x_coord; int y_coord;
    
    printf("Enter X coordinate (from 0 to 7) of the king");
    scanf("%d", &x_coord);
    printf("Enter Y coordinate (from 0 to 7) of the king");
    scanf("%d", &y_coord);

    if (board[x_coord][y_coord] != -1){
        board[x_coord][y_coord] = 1;
    }
    else {
        printf("This cell is not free try again: \n");
        put_the_king();
    }
    
}

void set_the_goal() {
    int x_coord; int y_coord;

    printf("Enter X coordinate (from 0 to 7) of the destintation point");
    scanf("%d", &x_coord);
    printf("Enter Y coordinate (from 0 to 7) of the destintation point");
    scanf("%d", &y_coord);

    if ((board[x_coord][y_coord] != -1) || (board[x_coord][y_coord] != 1)) {
        board[x_coord][y_coord] = 2;
    }
    else {
        printf("This cell is not free try again: \n");
        put_the_king();
    }


}

int get_the_area (){
    int x_king, y_king, x_goal, y_goal; // locals
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (board[i][j] == 1) { x_king = i; y_king = j; };
            if (board[i][j] == 2) { x_goal = i; y_goal = j; };
        }
    }

    return x_king, y_king, x_goal, y_goal;
}

int calculate_minimum_routes(int Ax, int Ay, int Bx, int By){
    int num_routes = 0;

    // in case A & B on the same axis, CHECKING the obstacles:
    if ((Ax == Bx) || (Ay == By)) { 
        // check Y - axis from B to A:
        if (Ax > Bx) {
            for (int i = Bx; i < Ax; ++i) {
                if (board[i][Ay] == -1) { num_routes = 0; }
            }
        } 

        // check Y - axis from A to B:
        if (Bx > Ax) {  
            for (int i = Ax; i < Bx; ++i) {
                if (board[i][Ay] == -1) { num_routes = 0; }
            }
        } 

        // check X - axis from B to A:
        if (Ay > By) { 
            for (int j = By; j < Ay; ++j) {
                if (board[Ax][j] == -1) { num_routes = 0; }
            }
        } 

        // check X - axis from A to B:
        if (By > Ay) {   
            for (int j = Ay; j < By; ++j) {
                if (board[Ax][j] == -1) { num_routes = 0; }
            }
        }  
        
    }
    else{ num_routes = 10; }
    


    return num_routes;
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


// _____________________PROBLEM N1:

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

// _____________________PROBLEM N2:

// a in power of b: recursive (classic)
int power_a_in_b(int a, int b) {
    if (b != 0) {
        return (a * power_a_in_b(a, b - 1));
    }
}

// a in power of b: recursive (faster)
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
    int a; int b; int answer;
    int num_obstcl;
    int num_routes;

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
    printf("\n");

    // Lesson 4 Problem 3:

    // 1 - initialisation:
    print_board();

    // 2 - put obstacles on the board:
    printf("Enter the number of obstacles on the board");
    scanf("%d", &num_obstcl);
    put_obstacles(num_obstcl);
    print_board();

    // 3 - put the king:
    printf("Enter the coordinates of the king on the board");
    put_the_king();
    print_board();

    // 4 - set the goal:
    printf("Set the destination point for the king on the board");
    set_the_goal();
    print_board();

    // 5 - scanning the new square area from point 1 to 2:
    x_king, y_king, x_goal, y_goal = get_the_area();
    //printf("%d", x_king); printf("%d", y_king); printf("%d", x_goal);   printf("%d", y_goal);
  
    // 6- calculate minimal number of routes:
    num_routes = calculate_minimum_routes(x_king, y_king, x_goal, y_goal);
    printf("%d", num_routes);
    printf("\n");

    // Theory - https://informatics.msk.ru/mod/book/view.php?id=266&chapterid=57 
    // Exapmle from the teacher - King from the upper left cell to the cell B

}




