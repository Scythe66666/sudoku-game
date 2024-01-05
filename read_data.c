#include "read_data.h"
#include <stdio.h>
#include "main_variables.h"

void read_csv(int Row, int Col, int array[Row][Col])
{
    int row, col, data;
    FILE *ptr = fopen("text", "r");
    if(ptr == NULL)
    {
        printf("error while opening the file\n");
    }
    while ((fscanf(ptr, "%d", &row) == 1) && (fscanf(ptr, "%d", &col) == 1) &&
           (fscanf(ptr, "%d", &data) == 1))
        array[row-1][col-1] = data;
}

void init_array_2D(int row, int col, int array[row][col])
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            array[i][j] = 0;
}

void display_array(int row, int col, int array[row][col])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}
