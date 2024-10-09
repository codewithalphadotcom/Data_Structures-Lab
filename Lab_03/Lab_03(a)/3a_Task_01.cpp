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
