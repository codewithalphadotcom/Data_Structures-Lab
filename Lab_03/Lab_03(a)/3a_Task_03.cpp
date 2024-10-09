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
