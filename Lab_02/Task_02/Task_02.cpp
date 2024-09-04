#include <iostream>
#include "module.cpp"
using namespace std;

int main()
{
    int rowsOne, columnsOne, rowsTwo, columnsTwo;
    // rowsOne, columnsOne represents the rows and columns of the first matrix i.e. matrixOne. same for the rowsTwo and columnsTwo.

    cout << "Enter the number of rows of the first matrix: ";
    cin >> rowsOne;

    cout << "Enter the number of columns of the first matrix: ";
    cin >> columnsOne;

    cout << "Enter the number of rows of the second matrix: ";
    cin >> rowsTwo;

    cout << "Enter the number of columns of the second matrix: ";
    cin >> columnsTwo;

    if (columnsOne != rowsTwo)
    {
        cout << "\nMatrix multiplication not possible.\nProgram Terminated......!\n";
        return 0;
    }

    int **matrixOne = new int *[rowsOne];
    for (int i = 0; i < rowsOne; i++)
    {
        matrixOne[i] = new int[columnsOne];
    }

    int **matrixTwo = new int *[rowsTwo];
    for (int i = 0; i < rowsTwo; i++)
    {
        matrixTwo[i] = new int[columnsTwo];
    }

    int **resultantMatrix = new int *[rowsOne];
    for (int i = 0; i < rowsOne; i++)
    {
        resultantMatrix[i] = new int[columnsTwo];
    }

    cout << endl;
    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < rowsOne; i++)
    {
        for (int j = 0; j < columnsOne; j++)
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrixOne[i][j];
        }
    }

    cout << endl;
    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < rowsTwo; i++)
    {
        for (int j = 0; j < columnsTwo; j++)
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrixTwo[i][j];
        }
    }

    matrixMultiplication(matrixOne, matrixTwo, resultantMatrix, rowsOne, columnsOne, rowsTwo, columnsTwo);

    cout<<"-----------------------------"<<endl;
    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < rowsOne; i++)
    {
        for (int j = 0; j < columnsTwo; j++)
        {
            cout << resultantMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<"--------------------"<<endl;

    for (int i = 0; i < rowsOne; i++)
    {
        delete[] matrixOne[i];
    }
    delete[] matrixOne;

    for (int i = 0; i < rowsTwo; i++)
    {
        delete[] matrixTwo[i];
    }
    delete[] matrixTwo;

    for (int i = 0; i < rowsOne; i++)
    {
        delete[] resultantMatrix[i];
    }
    delete[] resultantMatrix;

    return 0;
}