// Learning point - type alias:
/*
    renaming type of the varibale could be useful in the following cases:
    a) where meaning of the variable is more relevant for understanding than its type
    b) where type of the variable takes too many symbols

    SOLUTION: typedef

    // both variables are integer but both of them has different meanings
    typedef int carSpeed_t;
    typedef int planeSpeed_t;

    carSpeed_t bmw = 120;
    planeSpeed_t ssj = 480;

    // too long type of the variale:
    typedef std::vector<std::pair<std::string, int>> pairlist_t;
    pairlist_t pairlist;

    SOLUTION: type alias (after C++11)
    typedef double speed_t;
    using speed_t = double;

*/

// Learning point - arrays:
/*
    const uint16_t SIZE = 10;
    int arr1[SIZE] = {1, 2 , 3 , 4 , 5};

    cout << *(arr1 + 2); // access to the element #2 (or 3rd element of the array)

    //arrays could be symbolic:
    char name1[] = "Sergey"; // 7 bytes = 6 bytes for charaters + 1 byte for '0' (by compiler)
    char name2[] = {'S','o','n','i','a',0};
    char name3[] = {'S','o','n','i','a','\0'};

    // only for char cout could print whole array in to console:
    cout << name1 << ' ' << name2 << ' ' << name3;

    // N-dimansional arrays: 2D & 3D:
    int d2[2][2] = {{1 ,2},{3, 4}};
    bool d3[3][3][3] = {0};
*/

// Learning point - console input/output Problem in Qt5 !!! :
/*
    Surpisingy in QTcreator cin doesn't work:

    https://stackoverflow.com/questions/2321880/is-it-possible-to-use-cin-with-qt

    http://blog.harrix.org/article/2829 - SOLUTION


#include <iostream>

using namespace std;

char user_name[32] = {0};
uint16_t age;

int main()
{

    cout << "Input your name:" << endl;
    cin >> user_name;

    cout << "Input your age:" << endl;
    cin >> age;

    cout << "Hello, " << user_name << "Your age is " << age << endl;

    return 0;
}


*/

// Learning point - Enumeration & Structures & Union:
/*
    enum weekDays {Mon, Tue, Wed, Thu, Fri, Sat, Sun};

#include <iostream>
using namespace std;

struct Employee
    {
        int id;
        unsigned short age:5;
        double salary;
    };

struct myDate //Byte Fields (how to reduce the size of variable in the memory
{
    unsigned short Day:5; // 0..31
    unsigned short Month:4; // 0..15
    unsigned short Year:7; // 0..127
};

int main()
{
    Employee e1, e2;

    e1.id = 123456;
    e1.age = 28;
    e1.salary = 105000;

    e2 = {567890, 31, 152000};

    cout << e2.age << endl;
    cout << e1.age << endl;


    myDate day1;
    day1 = {5, 9, 21};
    cout << sizeof(day1);

    return 0;
}

*/

// Learning point - Byte Fields & Byte Flags

// HW2:
/*
В одном main.cpp файле / проекте:
1. Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double).
2. Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.
3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
4. * Создать структуру(struct) данных «Поле для игры в крестики - нолики» и снабдить его всеми необходимыми свойствами(подумайте что может понадобиться).
5. * *Создать структуру(struct MyVariant) объединяющую : union MyData(int, float, char) и 
      3 - и битовых поля(флага) указывающими какого типа значение в данный момент содержится в объединении(isInt, isFloat, isChar).
      Продемонстрировать пример использования в коде этой структуры.
Для программирования используйте установленную среду программирования(IDE).Если задания 4 и 5 кажутся сложными постарайтесь сделать первые 3.
*/

#include <iostream>
using namespace std;

int main()
{
    // Task 1
    {   
        unsigned short us_var = 1;
        short int si_var = 1;
        int i_var = 1;
        long long ll_var = 1;
        char c_var = 1;
        bool b_var = 1;
        float f_var = 1;
        double d_var = 1;

        cout << "unsighed short var is created and it takes: " << sizeof(us_var) << " bytes" << endl;
        cout << "short int var is created and it takes: " << sizeof(si_var) << " bytes" << endl;
        cout << "integer var is created and it takes: " << sizeof(i_var) << " bytes" << endl;
        cout << "long long var is created and it takes: " << sizeof(ll_var) << " bytes" << endl;
        cout << "char var is created and it takes: " << sizeof(c_var) << " bytes" << endl;
        cout << "bool var is created and it takes: " << sizeof(b_var) << " bytes" << endl;
        cout << "float var is created and it takes: " << sizeof(f_var) << " bytes" << endl;
        cout << "double var is created and it takes: " << sizeof(d_var) << " bytes" << endl;
    };

    // Task 2
    {
        enum gap_symbols{X, O, _ }; 
    };

    // Task 3
    {
        // Creating the array:
        enum gap_symbols { X, O, _ }; // X = 1, O = 1, _ = 2
        gap_symbols field_arr[3][3]; 

        // Its initialization: (initially the field is empty therefore each has _
        // We have cycles only on 4th lectures, therefore:
        field_arr[0][0] = _;
        field_arr[0][1] = _;
        field_arr[0][2] = _;

        field_arr[1][0] = _;
        field_arr[1][1] = _;
        field_arr[1][2] = _;

        field_arr[2][0] = _;
        field_arr[2][1] = _;
        field_arr[2][2] = _;

        //cout << field_arr[1][1];

    };

    // Task 4
    {
        struct Field_for_game
        {
            // field generation:
            enum gap_symbols { X, O, _ }; 
            gap_symbols field_arr[3][3]; 

            typedef unsigned short x_coordinate;
            typedef unsigned short y_coordinate;

            // players:
            typedef char player_1_name;
            typedef char player_2_name;

            typedef unsigned short player_1_vector[3]; // needs to calculate win conditions for 1st player
            typedef unsigned short player_2_vector[3]; // needs to calculate win conditions for 2nd player

            unsigned short win_condition : 2; // 4 possible outcomes from the game: win 1st 0b01 or win 2nd 0b10, initial 0b00, dead_heat 0b11 

            // calculating the order of the game. It helps to understand which player goes next. Moreover, it could be used to check the control sum. 
            typedef unsigned short order;   

        };

 
    };

    // Task 5
    {   // Here is the usefull links for stackoverflow https://stackoverflow.com/questions/9479424/how-to-determine-what-type-is-used-in-a-union 
        // Windows https://docs.microsoft.com/en-us/cpp/cpp/unions?view=msvc-160 
        
        struct MyVariant
        {
            union MyData
            {
                int int_var_in; 
                float float_var_in;  
                char char_var_in; 
            }; 

            unsigned short type_isInt : 1;
            unsigned short type_isFloat : 1;
            unsigned short type_isChar : 1;
        };

        // Example. Using this structure and bitflags to detect the type of the Union 
        MyVariant::MyData example_var; // creating the union object inside the structure
        MyVariant type_inside; // return the type flag

        cout << "Write integer variable inside the union:" << endl;
        cin >> example_var.int_var_in;
        type_inside = { 1, 0, 0 };
        
        // Check:
        cout << type_inside.type_isChar;
        cout << type_inside.type_isFloat;
        cout << type_inside.type_isInt;

        cout << "Write float variable inside the union:" << endl;
        cin >> example_var.float_var_in;
        type_inside = { 0, 1, 0 };

        // Check:
        cout << type_inside.type_isChar;
        cout << type_inside.type_isFloat;
        cout << type_inside.type_isInt;

        cout << "Write char variable inside the union:" << endl;
        cin >> example_var.char_var_in;
        type_inside = { 0, 0, 1 };

        // Check:
        cout << type_inside.type_isChar;
        cout << type_inside.type_isFloat;
        cout << type_inside.type_isInt;

    };

    return 0;
}

