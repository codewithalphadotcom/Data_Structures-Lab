#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int targetValue)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == targetValue)
        {
            return mid;
        }
        else if (arr[mid] < targetValue)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

void bubbleSort(int arr[], int size)
{
    // using bubble sort to sort the array...!
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertElement(int arr[], int &size, int position, int element)
{
    for (int i = size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++; // increment the size by 1 as we have inserted one new element...!
}

void findOrInsert(int employee_ids[], int &size, int roll)
{
    bubbleSort(employee_ids, size);

    int position = binarySearch(employee_ids, size, roll);
    if ((position < size) && (employee_ids[position] == roll))
    {
        cout << "Employee ID " << roll << " found at position " << (position + 1) << "." << endl;
    }
    else
    {
        insertElement(employee_ids, size, position, roll);
        cout << "Employee ID " << roll << " not found. Inserted at position " << (position + 1) << "." << endl;
    }
}

int main()
{
    int employee_id[] = {79, 51, 16, 24, 34, 91};
    int size = 6;
    int roll_no = 41;

    cout << "-------------------" << endl;
    findOrInsert(employee_id, size, roll_no);

    cout << "Updated Employee IDs: ";
    for (int i = 0; i < size; i++)
    {
        cout << employee_id[i] << " ";
    }
    cout << "\n----------------------------------------------------" << endl;
    return 0;
}
