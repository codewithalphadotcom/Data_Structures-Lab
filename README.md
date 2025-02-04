# Data Structures Lab Tasks.

_This repository contains the solution sets of all the assignments of Data Structures Course in my 3rd Semester._

## _Lab-02 (Array Data Structure)_

### Task-01

![Task-01](assets/images/Lab_02/Task_01.png)
1. _Implement Jagged arrays from the above pseudocode by taking a size of 5 and resizing it to 10 in each index._

#### Solution
```CPP
#include <iostream>
using namespace std;

int main()
{

    int **jaggedArray = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        jaggedArray[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            jaggedArray[i][j] = (i + j) + 1; // (i + j) + 1 => just adding some values to the array for testing
        }
    }

    cout << "--------------" << endl;
    cout << "Jagged Array Before Resizing: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Resizing the jagged array to 5 x 10
    for (int i = 0; i < 5; i++)
    {
        int *temp = new int[10];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = jaggedArray[i][j];
        }
        for (int j = 5; j < 10; j++)
        {
            temp[j] = 9; // placing 9 to the another 5x5 part of the array. 9 => universal number :)
        }
        delete[] jaggedArray[i];
        jaggedArray[i] = temp;
    }

    cout << "--------------" << endl;
    cout << "Jagged Array After Resizing: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating the memory here...!
    for (int i = 0; i < 5; i++)
    {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}
```

### Task-02

![Task-02](assets/images/Lab_02/Task_02.png)
2. _Create a header file called matrix_multuply.h that takes two arrays as input and multiplies them and outputs a multiplied array._
#### Solution
##### matrix_multiply.h
```CPP
#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H

using namespace std;

// prototype of the matrixMultiplication method!
// check module.cpp for definition.

void matrixMultiplication(int **matrixOne, int **matrixTwo, int **resultantMatrix, int rowsOne, int columnsOne, int rowsTwo, int columnsTwo);

#endif 
```

##### module.cpp
```CPP
#include <iostream>
#include "matrix_multiply.h"
using namespace std;

// definition of the declared method in matrix_multiply.h
void matrixMultiplication(int **matrixOne, int **matrixTwo, int **resultantMatrix, int rowsOne, int columnsOne, int rowsTwo, int columnsTwo)
{

    for (int i = 0; i < rowsOne; i++)
    {
        for (int j = 0; j < columnsTwo; j++)
        {
            for (int k = 0; k < columnsOne; k++)
            {
                resultantMatrix[i][j] = (resultantMatrix[i][j] + (matrixOne[i][k] * matrixTwo[k][j]));
            }
        }
    }
}
```

##### main.cpp
```CPP
#include <iostream>
#include "module.cpp"
using namespace std;

int main()
{
    int rowsOne, columnsOne, rowsTwo, columnsTwo;

    cout << "Enter the number of rows of the first matrix: ";
    cin >> rowsOne;

    cout << "Enter the number of columns of the first matrix: ";
    cin >> columnsOne;

    cout << "Enter the number of rows of the second matrix: ";
    cin >> rowsTwo;

    cout << "Enter the number of columns of the second matrix: ";
    cin >> columnsTwo;

    if (columnsOne != rowsTwo)
    {
        cout << "\nMatrix multiplication not possible.\nProgram Terminated......!\n";
        return 0;
    }

    int **matrixOne = new int *[rowsOne];
    for (int i = 0; i < rowsOne; i++)
    {
        matrixOne[i] = new int[columnsOne];
    }

    int **matrixTwo = new int *[rowsTwo];
    for (int i = 0; i < rowsTwo; i++)
    {
        matrixTwo[i] = new int[columnsTwo];
    }

    int **resultantMatrix = new int *[rowsOne];
    for (int i = 0; i < rowsOne; i++)
    {
        resultantMatrix[i] = new int[columnsTwo];
    }

    cout << endl;
    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < rowsOne; i++)
    {
        for (int j = 0; j < columnsOne; j++)
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrixOne[i][j];
        }
    }

    cout << endl;
    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < rowsTwo; i++)
    {
        for (int j = 0; j < columnsTwo; j++)
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrixTwo[i][j];
        }
    }

    matrixMultiplication(matrixOne, matrixTwo, resultantMatrix, rowsOne, columnsOne, rowsTwo, columnsTwo);

    cout<<"-----------------------------"<<endl;
    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < rowsOne; i++)
    {
        for (int j = 0; j < columnsTwo; j++)
        {
            cout << resultantMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<"--------------------"<<endl;

    for (int i = 0; i < rowsOne; i++)
    {
        delete[] matrixOne[i];
    }
    delete[] matrixOne;

    for (int i = 0; i < rowsTwo; i++)
    {
        delete[] matrixTwo[i];
    }
    delete[] matrixTwo;

    for (int i = 0; i < rowsOne; i++)
    {
        delete[] resultantMatrix[i];
    }
    delete[] resultantMatrix;

    return 0;
}
```

### Task-03
![Task-03](assets/images/Lab_02/Task_03.png)
#### Solution
```CPP
#include <iostream>
using namespace std;

class FriendsArray {
private:
    static const int n = 5;
    static bool friends[n][n];

public:
    static bool commonFriend(int personOne, int personTwo) {
        for (int i = 0; i < n; i++) {
            if ((friends[personOne][i]) && (friends[personTwo][i])) {
                return true;
            }
        }
        return false;
    }
};

// Initialize the static member
bool FriendsArray::friends[n][n] = {
    {false, true, false, true, false},
    {true, false, true, false, true},
    {false, true, false, false, false},
    {true, false, false, false, true},
    {true, true, false, true, false}
};

int main() {
    // test the program and verify by changing the index value of the two persons here...!
    int personOne = 2;
    int personTwo = 3;

    if (FriendsArray::commonFriend(personOne, personTwo)) {
        cout << personOne << " and " << personTwo << " have a common friend." << endl;
    } else {
        cout << personOne << " and " << personTwo << " have no common friend." << endl;
    }

    return 0;
}

```

### Task-04

![Task-04](assets/images/Lab_02/Task_04.png)

#### Solution
```CPP
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
```

### Task-05

![Task-05](assets/images/Lab_02/Task_05.png)

#### Solution
```CPP
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

```

## _Lab-03 (Linked-Lists)_

### Lab_03(a) - Singly Linked List

#### Task-01

![Task-01](assets/images/Lab_03/Lab_03(a)/Task_01.png)

##### Solution
```CPP
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLL
{
public:
    Node *head;
    SinglyLL() : head(nullptr) {}

    void insertNode(int val)
    {
        Node *node = new Node(val);
        if (!node)
        {
            cout << "Memory Allocation Failed!" << endl;
            return;
        }

        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }

    void ModifyLL()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *even = nullptr;
        Node *odd = nullptr;
        Node *evenTail = nullptr;
        Node *oddTail = nullptr;

        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data % 2 == 0)
            {
                if (even == nullptr)
                {
                    even = evenTail = temp;
                }
                else
                {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            }
            else
            {
                if (odd == nullptr)
                {
                    odd = oddTail = temp;
                }
                else
                {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            }
            temp = temp->next;
        }

        if (even == nullptr || odd == nullptr) // checking if either even or odd list is empty.
        {
            // if esa hai, then no need to merge these two lists
            return;
        }

        evenTail->next = odd;
        oddTail->next = nullptr;
        head = even;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

        delete temp; // deleting the temporary node.
    }
};

int main()
{
    cout << "-----------------" << endl;
    SinglyLL list;

    int num, element; // num => number of elements to be inserted in the list.
    cout << "Enter the number of elements to be inserted in the list: ";
    cin >> num;

    for (int i = 0; i < num; i++)
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
        cin >> element;
        list.insertNode(element); // inserting elements in the list.
    }

    cout << "Before Modification: ";
    list.printList();

    list.ModifyLL();
    cout << "After Modification: ";
    list.printList();
    cout << "------------------------------------" << endl;

    return 0;
}
```

#### Task-02

![Task-02](assets/images/Lab_03/Lab_03(a)/Task_02.png)

##### Solution
```CPP
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

class SinglyLL
{
public:
    Node *head;
    SinglyLL() : head(nullptr) {}

    void insertNode(int val)
    {
        Node *node = new Node(val);
        if (!node)
        {
            cout << "Memory Allocation Failed!" << endl;
            return;
        }

        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }

    bool is_palindrome()
    {
        if (head == nullptr)
        {
            cout << "Provided list is empty." << endl;
            return false;
        }
        if (head->next == nullptr)
        {
            cout << "List has only one element." << endl;
            return true;
        }

        int count = 0;
        Node *temp = head;
        // counting the number of elements in the given linked list.
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        int *elems = new int[count];
        temp = head;

        // copying all the values of linked list to an integer array.
        for (int i = 0; i < count; i++)
        {
            elems[i] = temp->value;
            temp = temp->next;
        }

        for (int i = 0; i < count / 2; i++)
        {
            // checking if the first and the last element are equal or not, and so on.
            if (elems[i] != elems[count - 1 - i])
            {
                delete[] elems;
                return false;
            }
        }
        delete[] elems;
        return true;
    }
};

int main()
{

    cout << "-----------------" << endl;
    SinglyLL list;

    int num, element;
    cout << "Enter the number of elements to be inserted in the list: ";
    cin >> num;

    for (int i = 0; i < num; i++)
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
        cin >> element;
        list.insertNode(element);
    }

    if (list.is_palindrome())
    {
        cout << "The Given list is a Palindrome." << endl;
        cout << "---------------------------------" << endl;
    }
    else
    {
        cout << "The Given list is NOT a Palindrome." << endl;
        cout << "----------------------------------------------" << endl;
    }

    Node *temp = list.head;
    while (temp != nullptr)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}
```

#### Task-03

![Task-03](assets/images/Lab_03/Lab_03(a)/Task_03.png)

##### Solution

```CPP
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *last;
    // last => last node of the list, last->next => first node of the list.

public:
    CircularLinkedList() : last(nullptr) {}

    void insertAtBeginning(int value)
    {
        Node *n = new Node(value);

        if (last == nullptr)
        {
            last = n;
            last->next = last;
        }
        else
        {
            n->next = last->next;
            last->next = n;
        }
    }

    void insertAtEnd(int value)
    {
        Node *n = new Node(value);
        if (last == nullptr)
        {
            last = n;
            last->next = last;
        }
        else
        {
            n->next = last->next;
            last->next = n;
            last = n;
        }
    }

    void insertAtGivenPosition(int value, int position)
    {
        Node *n = new Node(value);

        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node *temp = last->next;
        for (int i = 1; i < ((position - 1) && (temp != last)); ++i)
        {
            temp = temp->next;
        }

        if (temp == last && position != 2)
        {
            cout << "Position out of bounds" << endl;
            delete n;
            return;
        }

        n->next = temp->next;
        temp->next = n;

        if (temp == last)
        {
            last = n;
        }
    }

    void deleteNode(int value) // deleting the node according to the given value, not the pos!
    {
        if (last == nullptr)
        {
            cout << "List Doesnot contain any node...!" << endl;
            return;
        }

        Node *temp = last->next;
        Node *prev = last;

        do
        {
            if (temp->data == value)
            {
                if (temp == last)
                {
                    if (last->next == last)
                    {
                        delete last;
                        last = nullptr;
                    }
                    else
                    {
                        prev->next = temp->next;
                        last = prev;
                        delete temp;
                    }
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node not found." << endl;
    }

    void printList()
    {
        if (last == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        Node *temp = last->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "\n-------------------" << endl;
    }
};

int main()
{
    cout << "----------" << endl;
    CircularLinkedList list;

    list.insertAtEnd(0);
    list.insertAtEnd(7);
    list.insertAtEnd(2);
    list.printList();

    list.insertAtBeginning(9);
    list.printList();

    list.insertAtGivenPosition(18, 2);
    list.printList();

    list.deleteNode(9); // deleting the node with value 9
    list.printList();

    return 0;
}
```

### Lab_03(b) - Doubly Linked List

#### Task-01

![Task-01](assets/images/Lab_03/Lab_03(b)/Task_01.png)

##### Solution
```CPP
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *prev;
    Node *next;

    Node(int key, int data) : key(key), data(data), prev(nullptr), next(nullptr) {}
};

class CircularDoublyLinkedList
{
public:
    Node *head;

    CircularDoublyLinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int key, int data)
    {
        Node *n = new Node(key, data);
        if (head == nullptr)
        {
            head = n;
            head->prev = head;
            head->next = head;
        }
        else
        {
            Node *tail = head->prev;
            tail->next = n;
            n->prev = tail;
            n->next = head;
            head->prev = n;
        }
        cout << "Node (" << key << ", " << data << ") inserted at the End!" << endl
             << endl;
    }

    void insertAtBeginning(int key, int data)
    {
        Node *n = new Node(key, data);
        if (head == nullptr)
        {
            head = n;
            head->prev = head;
            head->next = head;
        }
        else
        {
            Node *tail = head->prev;
            n->next = head;
            head->prev = n;
            n->prev = tail;
            head = n;
            tail->next = head;
        }
        cout << "Node (" << key << ", " << data << ") inserted at the Beginning!" << endl
             << endl;
    }

    void insertAtPosition(int key, int data, int position)
    {
        if (position < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (position == 0)
        {
            insertAtBeginning(key, data);
        }
        else
        {
            Node *n = new Node(key, data);
            Node *current = head;
            for (int i = 0; i < position - 1; i++)
            {
                if (current == nullptr || current->next == head)
                {
                    cout << "Position out of Bounds" << endl;
                    return;
                }
                current = current->next;
            }
            n->next = current->next;
            current->next->prev = n;
            current->next = n;
            n->prev = current;
        }
        cout << "Node (" << key << ", " << data << ") inserted at Position: " << position << endl
             << endl;
    }

    void deleteNode(int key)
    {
        if (head == nullptr)
        {
            cout << "List is Empty...!" << endl;
            return;
        }
        Node *current = head;
        do
        {
            if (current->key == key)
            {
                if (current == head)
                {
                    if (head->next == head)
                    {
                        delete head;
                        head = nullptr;
                    }
                    else
                    {
                        head->prev->next = head->next;
                        head->next->prev = head->prev;
                        Node *temp = head;
                        head = head->next;
                        delete temp;
                    }
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                cout << "\nNode with key " << key << " deleted from the list!" << endl
                     << endl;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Node with key " << key << " not found!" << endl;
    }

    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is Empty...!" << endl;
            return;
        }
        Node *current = head;
        cout << "(key, data) = ";
        do
        {
            cout << "(" << current->key << ", " << current->data << ") ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    CircularDoublyLinkedList list;
    list.insertAtEnd(1, 5);
    list.insertAtEnd(2, 12);
    list.insertAtBeginning(0, 9);
    list.insertAtPosition(3, 4, 2);
    list.printList();

    list.deleteNode(2); // will delete the node with key 2 i.e. the second node in the list with data 12.
    list.printList();

    return 0;
}
```

#### Task-03

![Task-03](assets/images/Lab_03/Lab_03(b)/Task_03.png)

##### Solution
```CPP
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *next;
    Node *prev;

    Node(int value, int key) : data(value), key(key), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList
{
private:
    Node *head;
    int number_of_elements;

    Node *getNodeByKey(int key)
    {
        if (!head)
            return nullptr;
        Node *temp = head;
        do
        {
            if (temp->key == key)
                return temp;
            temp = temp->next;
        } while (temp != head);
        return nullptr;
    }

public:
    DoublyCircularLinkedList() : head(nullptr), number_of_elements(0) {}

    void append(int data)
    {
        Node *n = new Node(data, number_of_elements);
        number_of_elements++;
        if (!head)
        {
            head = n;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            tail->next = n;
            n->prev = tail;
            n->next = head;
            head->prev = n;
        }
    }

    void swap(int key1, int key2)
    {
        if (key1 == key2)
        {
            return;
        }
        Node *node1 = getNodeByKey(key1);
        Node *node2 = getNodeByKey(key2);

        if (!node1 || !node2)
        {
            return;
        }

        Node *node_one_prev = node1->prev;
        Node *node_one_next = node1->next;
        Node *node_two_prev = node2->prev;
        Node *node_two_next = node2->next;

        if (node_one_next == node2)
        {
            node1->next = node_two_next;
            node1->prev = node2;
            node2->next = node1;
            node2->prev = node_one_prev;
            node_one_prev->next = node2;
            node_two_next->prev = node1;
        }
        else if (node_two_next == node1)
        {
            node2->next = node_one_next;
            node2->prev = node1;
            node1->next = node2;
            node1->prev = node_two_prev;
            node_two_prev->next = node1;
            node_one_next->prev = node2;
        }
        else
        {
            node_one_prev->next = node2;
            node_one_next->prev = node2;
            node_two_prev->next = node1;
            node_two_next->prev = node1;

            node1->next = node_two_next;
            node1->prev = node_two_prev;
            node2->next = node_one_next;
            node2->prev = node_one_prev;
        }

        if (head == node1)
            head = node2;
        else if (head == node2)
            head = node1;
    }
    void display()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != head)
            {
                cout << "-";
            }
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    cout << "\n";
    DoublyCircularLinkedList list;
    int arr[] = {1, 7, 4, 2, 6, 4, 5, 3, 9, 8};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        list.append(arr[i]);
    }

    cout << "Initial Linked List: ";
    list.display();

    list.swap(3, 7);

    cout << "After Swapping: ";
    list.display();
    cout << "------------------------------------------\n";

    return 0;
}
```

#### Task-04

![Task-04](assets/images/Lab_03/Lab_03(b)/Task_04.png)

##### Solution
```CPP
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void append(int data)
    {
        if (!head)
        {
            head = new Node(data);
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }

    void extractAndReverse()
    {
        if (!head || !head->next)
        {
            return;
        }
        Node *oddIndex = head;
        Node *evenIndex = head->next;
        Node *evenIndexHead = evenIndex;

        while (oddIndex && evenIndex && evenIndex->next)
        {
            oddIndex->next = evenIndex->next;
            oddIndex = oddIndex->next;
            evenIndex->next = oddIndex->next;
            evenIndex = evenIndex->next;
        }
        oddIndex->next = nullptr;

        Node *prev = nullptr;
        Node *current = evenIndexHead;
        Node *next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        evenIndexHead = prev;

        oddIndex = head;
        while (oddIndex->next)
        {
            oddIndex = oddIndex->next;
        }
        oddIndex->next = evenIndexHead;
    }
    void Display() const
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data;
            temp = temp->next;
            if (temp)
            {
                cout << "->";
            }
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    int n, elem;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

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
        cin >> elem;
        list.append(elem);
    }

    cout << "\nOriginal List: ";
    list.Display();
    list.extractAndReverse();

    cout << "Modified List: ";
    list.Display();
    cout << endl;

    return 0;
}
```

## _Lab-04 (Algorithms)_

### Task-01

![Task-01](assets/images/Lab_04/Lab_04(a)/Task_01.png)

_1. Implement the bubble sort algorithm to sort the in descending order (starting from the initial pass)._

_Take array[10]= {5,1,3,6,2,9,7,4,8,10}. You can also take your array as user input._

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