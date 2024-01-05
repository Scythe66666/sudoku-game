#include <stdio.h>
#include <unistd.h>
#include "main_variables.h"
#include "./sudoku.h"
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

void find_empty_CoOrdinates(int row, int col, int array[row][col])
{
    for(int i = empty_index_row; i < SIZE; i++)
        for (int j = empty_index_col; j < SIZE; j++) 
            if(!array[i][j])
            {
                empty_index_col = j;
                empty_index_row = i;
                return ;
            }   
}

void check_correct();
