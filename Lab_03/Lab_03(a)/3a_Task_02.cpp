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