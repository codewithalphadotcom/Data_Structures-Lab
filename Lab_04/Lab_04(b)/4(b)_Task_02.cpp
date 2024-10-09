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
