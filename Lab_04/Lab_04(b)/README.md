## _Lab-04(b`) - Searching Algorithms_

### Task-01

![Task-01](../../assets/images/Lab_04/Lab_04(b)/Task_01.png)

#### Solution

```CPP
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
```

### Task-02

![Task-02](../../assets/images/Lab_04/Lab_04(b)/Task_02.png)

#### Solution

```CPP
#include <iostream>
using namespace std;

bool isUniformlyDistributed(int data[], int size)
{
    int deviation = 5;
    if (size < 2)
    {
        return true;
    }
    int diff = data[1] - data[0];
    for (int i = 2; i < size; i++)
    {
        int currentDiff = data[i] - data[i - 1];
        if (abs(currentDiff - diff) > deviation)
        {
            return false;
        }
    }
    return true;
}

int interpolationSearch(int arr[], int size, int element)
{
    int startIndex = 0;
    int endIndex = size - 1;

    while ((startIndex <= endIndex) && (element >= arr[startIndex]) && (element <= arr[endIndex]))
    {
        // Interpolation formula
        int pos = startIndex + ((element - arr[startIndex]) * (endIndex - startIndex)) / (arr[endIndex] - arr[startIndex]);

        if (arr[pos] == element)
        {
            return pos;
        }

        if (arr[pos] < element)
        {
            startIndex = pos + 1;
        }
        else
        {
            endIndex = pos - 1;
        }
    }

    // If Element Not Found, return -1...!
    return -1;
}

void bubbleSort(int data[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int num;

    cout << "Enter the number of elements: ";
    cin >> num;

    int *data = new int[num];

    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            cout << "Enter " << (i + 1) << "st element: ";
        }
        else if (i == 1)
        {
            cout << "Enter " << (i + 1) << "nd element: ";
        }
        else if (i == 2)
        {
            cout << "Enter " << (i + 1) << "rd element: ";
        }
        else
        {
            cout << "Enter " << (i + 1) << "th element: ";
        }
        cin >> data[i];
    }

    bool sorted = true;
    for (int i = 1; i < num; i++)
    {
        if (data[i] < data[i - 1])
        {
            sorted = false;
            break;
        }
    }

    if (!sorted)
    {
        bubbleSort(data, num);
    }

    if (!isUniformlyDistributed(data, num))
    {
        cout << "Data is not uniformly distributed.\nProgram Terminated...!" << endl;
        delete[] data;
        return 1;
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int index = interpolationSearch(data, num, target);

    if (index != -1)
    {
        cout << "Element found at position " << (index + 1) << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
    delete[] data;
    return 0;
}
```