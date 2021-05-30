#include "gejm_of_lajf.h"
//#include<SFML/Graphics.hpp>
#include<ctime>
#include<iostream>
#include<iomanip>

// COLOR / RESET FOR PRINT
#define BOLDBLUE "\033[1m\033[34m"
#define RED     "\033[1m\033[31m"
#define RESET   "\033[0m"

// FOR RANDOM FUNCTION
const short my_min{ 1 };
const short my_max{ 100 };

gejm_of_lajf::gejm_of_lajf() // DEFAULT CONSTRUCTOR
{
    srand(time(nullptr)); // START SEED

    for (unsigned i = 0; i < ROWS; i++)  // PREVENT NEGATIVE NUMBER
    {
        for (unsigned j = 0; j < COLUMNS; j++)
        {
            // RANDOM CALL FOR GENERATION AT (X,Y)
            this->my_generation[i][j] = random();
        }
    }
}

void gejm_of_lajf::next_generation() // NEXT GENERATION OF CELLS
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (cell_occupied(i,j)) // IF OCCUPIED AT POSITION(X,Y)
            {
                // UNDERPOPULATION || OVERPOPULATION
                if (neighbours_number(i,j) < 2 || neighbours_number(i, j) > 3)
                {
                    my_next_generation[i][j] = 0;
                }
                else //OK
                {
                    my_next_generation[i][j] = 1;
                }
            }
            else // IF NOT OCCUPIED
            {
                // MEETS REQUIREMENTS
                if (neighbours_number(i,j) == 3)
                {
                    my_next_generation[i][j] = 1;
                }
                else // NOT
                {
                    my_next_generation[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) // CURRENT GENERATION EQUALS NEW GENERATION
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            my_generation[i][j] = my_next_generation[i][j]; // NEW/NEXT
        }
    }
}

void gejm_of_lajf::draw() // PRINT TO SCREEN
{
    system("CLS"); // CLEAR SCREEN

    for (unsigned i = 0; i < ROWS; i++) // PREVENT NEGATIVE NUMBER
    {
        for (unsigned j = 0; j < COLUMNS; j++)
        {
            if (this->my_generation[i][j] == 0)
            {
                // EMPTY
                std::cout << BOLDBLUE << std::setw(2.0) << 'O' << RESET;
            }
            else
            {
                // FILL
                std::cout << RED << std::setw(2.0) << 'O' << RESET;
            }
        }
        std::cout << std::endl;
    }
}

bool gejm_of_lajf::random() // RANDOM 
{
    int n{ rand() % (my_max - my_min + my_min) + my_min };
    if (n <= 25) return true;
    else return false;
}

bool gejm_of_lajf::cell_occupied(int i, int j) // CHECK IF OCCUPIED
{
    if (my_generation[i][j] == false) return false;
    else return true;
}

//RETURN NUMBER OF NEIGH FOR GIVEN POSITION(X,Y)->

int gejm_of_lajf::neighbours_number(int i, int j) {

    // NEIGHBOURS CONSTITUTION->
    
    // A B C    FIRST ROW (upper left, upper mid, upper right)
    // D E F    SECOND ROW (mid left, mid mid(current), mid right)
    // G H I    THIRD (lower left, lower mid, lower right)

    // SET->
    int counter{ 0 };
    bool A(1), B(1), C(1); // FIRST ROW
    bool D(1), E(1), F(1); // FIRST ROW
    bool G(1), H(1), I(1); // THIRD ROW

    // ROWS
    if (i == 0) { A = 0, B = 0, C = 0; } // FIRST
    if (i == (ROWS-1)) { G = 0, H = 0, I = 0; } // THIRD

    // COLLUMNS
    if (j == 0) { A = 0, D = 0, G = 0; } // FIRST
    if (j == (COLUMNS - 1)) { C = 0, F = 0, I = 0; } // THIRD

    // CALCULATION LOGIC-> IF TRUE COUNTER++

    // FIRST ROW
    if (A) { if (my_generation[i - 1][j - 1] == 1) { counter++; } }
    if (B) { if (my_generation[i - 1][j] == 1) { counter++; } }
    if (C) { if (my_generation[i - 1][j + 1] == 1) { counter++; } }

    // SECOND ROW
    if (D) { if (my_generation[i][j - 1] == 1) { counter++; } }
    // (E)
    if (F) { if (my_generation[i][j + 1] == 1) { counter++; } }

    // THIRD ROW
    if (G) { if (my_generation[i + 1][j - 1] == 1) { counter++; } }
    if (H) { if (my_generation[i + 1][j] == 1) { counter++; } }
    if (I) { if (my_generation[i + 1][j + 1] == 1) { counter++; } }

    // RETURN NUMBER OF NEIGHBOURS->
    return counter;
}
