#include "main.h"
#include <stdio.h>
#include "main_variables.h"


int main()
{
    int array[SIZE][SIZE];
    init_array_2D(SIZE, SIZE, array);
    printf("\n\n");
    read_csv(SIZE, SIZE, array);
    // display_array();
    print_sudoku(SIZE, SIZE, array);
}
