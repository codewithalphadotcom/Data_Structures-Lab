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
