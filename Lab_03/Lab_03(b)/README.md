### Lab_03(b) - Doubly Linked List

#### Task-01

![Task-01](../../assets/images/Lab_03/Lab_03(b)/Task_01.png)

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

![Task-03](../../assets/images/Lab_03/Lab_03(b)/Task_03.png)

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

![Task-04](../../assets/images/Lab_03/Lab_03(b)/Task_04.png)

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