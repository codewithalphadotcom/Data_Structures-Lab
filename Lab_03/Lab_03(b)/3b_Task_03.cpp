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
