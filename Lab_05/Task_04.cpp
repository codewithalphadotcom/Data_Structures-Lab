#include <iostream>
using namespace std;

int recursiveArraySum(int **arr, int sizes[], int dim)
{
    if (dim == 1)
    {
        int sum = 0;
        for (int i = 0; i < sizes[0]; i++)
        {
            sum += arr[0][i];
        }
        return sum;
    }

    int sum = 0;
    for (int i = 0; i < sizes[0]; i++)
    {
        sum += recursiveArraySum(arr + i, sizes + 1, dim - 1);
    }
    return sum;
}

int main()
{
    int first_array[] = {9, 18, 45, 3};
    int second_array[] = {33, 41, 32, 13};
    int third_array[] = {12, 34, 44, 22};

    int *arr[] = {first_array, second_array, third_array};

    // arr is a 2D array so, 
    int dimensions = 2;
    int sizes[] = {3, 4}; // 3 -> number of arrays in arr, 4 -> number of elements in each array

    int sum = recursiveArraySum(arr, sizes, dimensions);
    cout << "Sum of all the elements of these three arrays is: " << sum << endl;

    return 0;
}