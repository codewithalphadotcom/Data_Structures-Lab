#include <iostream>
using namespace std;

void Display(double gpa[][4], string Departments[], int courses[], int number_of_departments)
{
    for (int i = 0; i < number_of_departments; i++)
    {
        cout << "------------" << endl;
        cout << "Department: " << Departments[i] << endl;
        for (int j = 0; j < courses[i]; j++)
        {
            cout << "Course " << j + 1 << ":\t GPA: " << gpa[i][j] << endl;
        }
        cout << "-------------------------------------" << endl;
    }
}

int main()
{
    const int number_of_departments = 4;
    int courses[] = {3, 4, 2, 1}; // according to Departments

    string Departments[number_of_departments] = {
        "Software Engineering (SE)",
        "Artificial Intelligence (AI)",
        "Computer Science (CS)",
        "Data Science (DS)",
    };

    // hardcoding the values for testing purposes...
    double gpa[number_of_departments][4] = {
        {3.67, 3.48, 3.51},      // Software Engineering
        {3.78, 3.85, 4.0, 3.97}, // Artificial Intelligence
        {3.24, 3.92},            // Computer Science
        {3.9}                    // Data Science
    };

    Display(gpa, Departments, courses, number_of_departments);
    return 0;
}