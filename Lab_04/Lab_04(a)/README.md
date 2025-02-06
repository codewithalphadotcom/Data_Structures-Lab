## _Lab-04 (Algorithms)_

### Task-01

![Task-01](../../assets/images/Lab_04/Lab_04(a)/Task_01.png)

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

### Task-02

![Task-02](../../assets/images/Lab_04/Lab_04(a)/Task_02.png)

#### Solution
```CPP
#include <iostream>
using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    void display()
    {
        if (day < 10 && month < 10)
        {
            cout << "0" << day << "/0" << month << "/" << year << endl;
        }
        else if (day < 10)
        {
            cout << "0" << day << "/" << month << "/" << year << endl;
        }
        else if (month < 10)
        {
            cout << day << "/0" << month << "/" << year << endl;
        }
        else
        {
            cout << day << "/" << month << "/" << year << endl;
        }
    }
};

void selectionSort(Date arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].year < arr[minIndex].year)
            {
                minIndex = j;
            }
        }
        Date temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    Date dates[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Day for record " << (i + 1) << ": ";
        cin >> dates[i].day;
        cout << "Enter Month for record " << (i + 1) << ": ";
        cin >> dates[i].month;
        cout << "Enter Year for record " << (i + 1) << ": ";
        cin >> dates[i].year;
        cout << endl;
    }

    selectionSort(dates, 5);
    cout << "----------------" << endl;
    cout << "Sorted Dates based on year:" << endl;
    for (int i = 0; i < 5; i++)
    {
        dates[i].display();
    }
    cout << "--------------------------------------" << endl;

    return 0;
}
```

### Task-03

![Task-03](../../assets/images/Lab_04/Lab_04(a)/Task_03.png)

#### Solution
```CPP
#include <iostream>
#include <stdexcept>
using namespace std;

class Employee
{
private:
    string designation;
    int priority;

public:
    void setDesignation(string designation)
    {
        this->designation = designation;
    }
    void setPriority(int priority)
    {
        this->priority = priority;
    }
    string getDesignation()
    {
        return designation;
    }
    int getPriority()
    {
        return priority;
    }
};

int getPriority(const string &designation)
{
    if (designation == "CEO")
    {
        return 1;
    }
    if (designation == "CTO")
    {
        return 2;
    }
    if (designation == "CFO")
    {
        return 3;
    }
    if (designation == "VP")
    {
        return 4;
    }
    if (designation == "MGR")
    {
        return 5;
    }
    if (designation == "EMP")
    {
        return 6;
    }

    // if not any one of the above designation is found, throw an exception!
    throw invalid_argument("Unknown Designation: " + designation);
}

void insertionSort(Employee employees[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Employee temp = employees[i];
        int j = i - 1;
        while ((j >= 0) && (employees[j].getPriority() > temp.getPriority()))
        {
            employees[j + 1] = employees[j];
            j = j - 1;
        }
        employees[j + 1] = temp;
    }
}

int main()
{
    string designations[] = {"EMP", "CFO", "MGR", "EMP", "VP", "CTO", "MGR", "CEO"};
    int numEmployees = sizeof(designations) / sizeof(designations[0]);

    Employee employees[numEmployees];
    for (int i = 0; i < numEmployees; i++)
    {
        employees[i].setDesignation(designations[i]);
        employees[i].setPriority(getPriority(designations[i]));
    }

    cout << "------------------" << endl;
    cout << "Before Sorting:" << endl;
    for (int i = 0; i < numEmployees; i++)
    {
        cout << employees[i].getDesignation() << " ";
    }
    cout << "\n\n";

    insertionSort(employees, numEmployees);
    cout << "Seating Arrangement according to Designation Priority: ";
    for (int i = 0; i < numEmployees; i++)
    {
        cout << employees[i].getDesignation() << " ";
    }
    cout << "\n--------------------------------------------------" << endl;

    return 0;
}
```

### Task-04

![Task-04](../../assets/images/Lab_04/Lab_04(a)/Task_04.png)

### Solution
```CPP
#include <iostream>
using namespace std;

// Custom gap sequence: Hibbard's sequence (2^k - 1), covered this topic in Theory classes.
int getNextGap(int gap)
{
    int k = 1;
    while ((1 << k) - 1 < gap)
    {
        k++;
    }
    return (1 << (k - 1)) - 1;
}

void shellSort(int weights[], int n)
{
    int gap = getNextGap(n);
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = weights[i];
            int j = i;

            while ((j >= gap) && (weights[j - gap] > temp))
            {
                weights[j] = weights[j - gap];
                j -= gap;
            }

            weights[j] = temp;
        }
        gap = getNextGap(gap);
    }
}

void printWeights(int weights[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << weights[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int weights[] = {98, 68, 51, 60, 79, 75, 92, 64};
    int n = sizeof(weights) / sizeof(weights[0]);

    cout << "--------------\n";
    cout << "Original Weights: ";
    printWeights(weights, n);

    shellSort(weights, n);

    cout << "Sorted Weights: ";
    printWeights(weights, n);
    cout << "-----------------------------------------\n";

    return 0;
}
```

### Task-04

![Task-05](../../assets/images/Lab_04/Lab_04(a)/Task_05.png)

#### Solution
```CPP
#include <iostream>
#include <cmath>
using namespace std;

void combSort(float arr[], int n, float shrink_factor = 1.5)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = int(((float)gap / shrink_factor));
        if (gap < 1)
        {
            gap = 1;
        }
        swapped = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    float prices[] = {2399.00, 4999.00, 89.99, 9999.99, 7499.99, 6999.49, 1299.49};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "--------------\n";
    cout << "Original Prices: ";
    for (int i = 0; i < n; i++)
    {
        cout << prices[i] << " ";
    }

    combSort(prices, n); // the third argument i.e. shrink_factor is optional and has a default value of 1.5!

    cout << "\nSorted prices: ";
    for (int i = 0; i < n; i++)
    {
        cout << prices[i] << " ";
    }
    cout << "\n------------------------------------------------------------------\n";

    return 0;
}
```