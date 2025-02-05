# Data Structures Lab Tasks.

_This repository contains the solution sets of all the assignments of Data Structures Course in my 3rd Semester._



## _Lab-04 (Algorithms)_

### Task-01

![Task-01](assets/images/Lab_04/Lab_04(a)/Task_01.png)

_1. Implement the bubble sort algorithm to sort the in descending order (starting from the initial pass)._

_Take array[10]= {5,1,3,6,2,9,7,4,8,10}. You can also take your array as user input._

#### Solution

```CPP
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```