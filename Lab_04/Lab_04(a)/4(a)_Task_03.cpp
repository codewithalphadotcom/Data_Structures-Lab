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
