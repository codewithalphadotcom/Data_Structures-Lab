#include <iostream>
using namespace std;

int main()
{

    int **jaggedArray = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        jaggedArray[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            jaggedArray[i][j] = (i + j) + 1; // (i + j) + 1 => just adding some values to the array for testing
        }
    }

    cout << "--------------" << endl;
    cout << "Jagged Array Before Resizing: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Resizing the jagged array to 5 x 10
    for (int i = 0; i < 5; i++)
    {
        int *temp = new int[10];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = jaggedArray[i][j];
        }
        for (int j = 5; j < 10; j++)
        {
            temp[j] = 9; // placing 9 to the another 5x5 part of the array. 9 => universal number :)
        }
        delete[] jaggedArray[i];
        jaggedArray[i] = temp;
    }

    cout << "--------------" << endl;
    cout << "Jagged Array After Resizing: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating the memory here...!
    for (int i = 0; i < 5; i++)
    {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}