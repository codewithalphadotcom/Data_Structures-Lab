#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

bool searchValue(Node *n, int target)
{
    if (n == nullptr)
    {
        return false;
    }

    if (n->data == target)
    {
        return true;
    }

    return searchValue(n->next, target);
}

int main()
{

    int target = 9;

    Node *head = new Node(9);
    head->next = new Node(18);
    head->next->next = new Node(108);
    head->next->next->next = new Node(432);

    if (searchValue(head, target))
    {
        cout << target << " does exists in the linked list!" << endl;
    }
    else
    {
        cout << target << " doesnot exists in the linked list!" << endl;
    }

    Node *curr = head;
    while (curr != nullptr)
    {
        Node *n = curr->next;
        delete curr;
        curr = n;
    }

    return 0;
}