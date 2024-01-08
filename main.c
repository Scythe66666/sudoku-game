#include "main.h"
#include <stdio.h>
#include <limits.h>
#include "main_variables.h"
static int func_count = 0;
//invoke this function with array name and  0 as parameters
//function is responsible for adding number at the index 
//depending on the value of num then checking if the number
//is valid at given position and then passing on the array 
//to the its recursive function  with the value and checking
//if with the value can any sudoku be made 
int solve(int array[SIZE][SIZE], int num)
{
    func_count++;
    if(num == SIZE * SIZE)
        return 1;
    int row = num / SIZE;
    int col = num % SIZE;
    //this for loop will create branches for a single cell in sudoku 
    if(array[row][col] == 0)
    {
        for (int i = 1; i <= SIZE; i++) {
            array[row][col] = i;
            int solve_value = 0; 
            if(check_correct(SIZE, array, row, col))
            {
                solve_value = solve(array, num + 1);
            }
            else {
                array[row][col] = 0;
                continue;
            }     
            if(solve_value == 1)
            {
                return  1;
            }
            array[row][col] = 0;
        }
        return 0;
    }
    return solve(array, num + 1);
}

int main()
{
    int array[SIZE][SIZE];
    init_array_2D(SIZE, SIZE, array);
    printf("\n\n");
    read_csv(SIZE, SIZE, array);

    // display_array();
    print_sudoku(SIZE, SIZE, array);
    if(solve(array, 0))
       print_sudoku(SIZE, SIZE, array);
    else {
         printf("there is something wrong in the solving method\n");
         print_sudoku(SIZE, SIZE, array);
    }
}
