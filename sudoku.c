#include "./sudoku.h"
#include "main_variables.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
int n_col[SIZE] = {0};
int n_row[SIZE] = {0};
int empty_index_row = 0;
int empty_index_col = 0;

void print_sudoku(int row, int col, int array[row][col])
{
    for (int i = 0; i < row; i++)
    {
        if (i % 3 == 0)
            printf(" __________________________\n");
        for (int j = 0; j < col; j++)
        {
            if (j % 3 == 0)
            {
                printf(" | ");
                if (array[i][j] == 0)
                    printf("  ");
                else
                {
                    n_row[i]++;
                    n_col[j]++;
                    printf("%d ", array[i][j]);
                }
            }
            else
            {

                if (array[i][j] == 0)
                    printf("  ");
                else
                {
                    n_row[i]++;
                    n_col[j]++;
                    printf("%d ", array[i][j]);
                }
            }
        }
        printf(" |");
        printf("\n");
    }
    printf(" __________________________\n");
}

void find_empty_CoOrdinates(int size, int array[size][size])
{
    for (int i = empty_index_row; i < size; i++)
        for (int j = empty_index_col; j < size; j++)
            if (!array[i][j])
            {
                empty_index_col = j;
                empty_index_row = i;
                return;
            }
}

/*
 * \brief This functions checks if the number that is added on index is valid
 * or not
 * \param index index on which we are going to perform the check in form of
 * row *10 +col
 * */
int check_correct(int size, int array[size][size], int index)
{
    int row = index / 10;
    int col = index % 10;
    int num = array[row][col];
    int sub_grid_no = row / size + col;
    int count = 0;
    // row check
    for (int i = 0; i < size; i++)
    {
        if (array[row][i] == num)
        {
            if (count)
            {
                // printf("row wrong\n");
                return 0;
            }
            count++;
        }
    }
    count = 0;
    // col check
    for (int i = 0; i < size; i++)
    {
        if (array[i][col] == num)
        {
            if (count)
            {
                // printf("col wrong\n");
                return 0;
            }
            count++;
        }
    }
    count = 0;
    // sub grid check
    for (int i = 0; i < sqrt(size); i++)
    {
        for (int j = 0; j < sqrt(size); j++)
        {
            if (array[(sub_grid_no / 3) * 3 + i][(sub_grid_no % 3) * 3 + j] ==
                num)
            {
                if (count)
                {
                    // printf("sub-grid wrong\n");
                    return 0;
                }
                count++;
            }
        }
    }
    return 1;
}
