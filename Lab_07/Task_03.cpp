#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right, bool ascending)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (ascending)
        {
            if (leftArr[i] <= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
        }
        else
        {
            if (leftArr[i] >= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right, bool ascending)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);

        merge(arr, left, mid, right, ascending);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << "Enter " << i + 1 << "st element: ";
        }
        else if (i == 1)
        {
            cout << "Enter " << i + 1 << "nd element: ";
        }
        else if (i == 2)
        {
            cout << "Enter " << i + 1 << "rd element: ";
        }
        else
        {
            cout << "Enter " << i + 1 << "th element: ";
        }
        cin >> arr[i];
    }

    int *descendingOrder_array = new int[n];
    for (int i = 0; i < n; i++)
    {
        descendingOrder_array[i] = arr[i];
    }

    mergeSort(arr, 0, n - 1, true);
    mergeSort(descendingOrder_array, 0, n - 1, false);

    cout << "\nSorted array in ascending order: ";
    printArray(arr, n);

    cout << "Sorted array in descending order: ";
    printArray(descendingOrder_array, n);

    delete[] arr;
    delete[] descendingOrder_array;

    return 0;
}