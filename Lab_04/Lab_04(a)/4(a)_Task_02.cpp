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
