#include <iostream>
#include "matrix_multiply.h"
using namespace std;

// definition of the declared method in matrix_multiply.h
void matrixMultiplication(int **matrixOne, int **matrixTwo, int **resultantMatrix, int rowsOne, int columnsOne, int rowsTwo, int columnsTwo)
{

    for (int i = 0; i < rowsOne; i++)
    {
        for (int j = 0; j < columnsTwo; j++)
        {
            for (int k = 0; k < columnsOne; k++)
            {
                resultantMatrix[i][j] = (resultantMatrix[i][j] + (matrixOne[i][k] * matrixTwo[k][j]));
            }
        }
    }
}