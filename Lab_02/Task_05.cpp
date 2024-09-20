#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "\nEnter the number of rows: ";
    cin >> rows;
    cout << endl;

    string **seatingChart = new string *[rows];
    int *seatsPerRow = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        int number_of_seats;
        if (i == 0)
        {
            cout << "Enter the number of seats in " << (i + 1) << "st row " << ": ";
        }
        else if (i == 1)
        {
            cout << "Enter the number of seats in " << (i + 1) << "nd row " << ": ";
        }
        else if (i == 2)
        {
            cout << "Enter the number of seats in " << (i + 1) << "rd row " << ": ";
        }
        else
        {
            cout << "Enter the number of seats in " << (i + 1) << "th row " << ": ";
        }
        cin >> number_of_seats;
        seatingChart[i] = new string[number_of_seats];
        seatsPerRow[i] = number_of_seats;

        for (int j = 0; j < number_of_seats; j++)
        {
            cout << "Enter the name for seat " << j + 1 << " in row " << i + 1 << ": ";
            cin >> seatingChart[i][j];
        }
        cout << "-----------------------------" << endl;
    }

    cout << "\n--------------" << endl;
    cout << "Seating Chart: " << endl;

    for (int i = 0; i < rows; i++)
    {
        if (i == 0)
        {
            cout << i + 1 << "st row: ";
        }
        else if (i == 1)
        {
            cout << i + 1 << "nd row: ";
        }
        else if (i == 2)
        {
            cout << i + 1 << "rd row: ";
        }
        else
        {
            cout << i + 1 << "th row: ";
        }

        for (int j = 0; j < seatsPerRow[i]; j++)
        {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] seatingChart[i];
    }
    delete[] seatingChart;
    delete[] seatsPerRow;

    return 0;
}
