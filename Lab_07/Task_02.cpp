#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n, bool ascending = true)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }

    // reverse the array for descending order
    if (!ascending)
    {
        int left = 0, right = n - 1;
        while (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
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

    radixsort(arr, n);
    radixsort(descendingOrder_array, n, false);

    cout << "\nSorted array in ascending order: ";
    printArray(arr, n);

    cout << "Sorted array in descending order: ";
    printArray(descendingOrder_array, n);

    delete[] arr;
    delete[] descendingOrder_array;

    return 0;
}