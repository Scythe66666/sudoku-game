#include <stdio.h>
#include <unistd.h>
#define SIZE 9
int n_col[SIZE] = {0};
int n_row[SIZE] = {0};


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

void read_csv(int Row, int Col, int array[Row][Col])
{
    int row, col, data;
    FILE *ptr = fopen("text", "r");
    while ((fscanf(ptr, "%d", &row) == 1) && (fscanf(ptr, "%d", &col) == 1) &&
           (fscanf(ptr, "%d", &data) == 1))
        array[row-1][col-1] = data;
}

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

int main()
{
    int array[SIZE][SIZE];
    init_array_2D(SIZE, SIZE, array);
    printf("\n\n");
    read_csv(SIZE, SIZE, array);
    // display_array();
    print_sudoku(SIZE, SIZE, array);
}
