## _Lab-03 (Linked-Lists)_

### Lab_03(a) - Singly Linked List

#### Task-01

![Task-01](../../assets/images/Lab_03/Lab_03(a)/Task_01.png)

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

![Task-02](../../assets/images/Lab_03/Lab_03(a)/Task_02.png)

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

![Task-03](../../assets/images/Lab_03/Lab_03(a)/Task_03.png)

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
