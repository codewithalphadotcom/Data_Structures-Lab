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
