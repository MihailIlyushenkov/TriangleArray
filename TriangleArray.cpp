#include <stdio.h>
#include <stdlib.h>

static const size_t SIZEOFINT = sizeof(int);

int * TrArrInput(size_t * Arr_size, FILE *filename);
void TrArrOutp(const int * Array, const size_t size);
int GetData(const int * Array, const size_t row, const size_t collumn);


int main(void)
{
    FILE *DataFile = NULL;
    size_t size = 0;

    DataFile = fopen("DataFile.txt", "r");

    int * Array = TrArrInput(&size, DataFile);

    TrArrOutp(Array, size);

    printf("%d", GetData(Array, 2, 2));
}


int * TrArrInput(size_t * Arr_size, FILE *filename)
{
    int * Array = NULL;

    fscanf(filename, "%d", Arr_size);


    size_t arr_cells = (*Arr_size*(*Arr_size+1))/2;

    Array = (int *) calloc(arr_cells, SIZEOFINT);

    for (size_t i = 0; i < arr_cells; i++)
    {
        fscanf(filename, "%d", &Array[i]);
    }

    return Array;

}

void TrArrOutp(const int * Array, const size_t size)
{
    size_t row_lenght = 1;
    size_t i = 0;
    for (size_t row = 0; row < size; row++)
    {
        printf("%d:", row);
        for (int coll_num = 0; coll_num < row_lenght; coll_num ++)
        {
            printf("%3d", Array[i]);
            i++;
        }

        printf("\n");
        row_lenght += 1;
    }
}

int GetData(const int * Array, const size_t row, const size_t collumn)
{
    if (collumn > row)
    {
        return NULL;
    }

    return *(Array + (row*(row+1)/2) + collumn);
}
