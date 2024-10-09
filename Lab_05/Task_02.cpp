#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int value) : val(value), next(nullptr) {}
};

int findLength(Node *n, int count)
{
    if (n == nullptr)
    {
        return count;
    }
    return findLength(n->next, count + 1);
}

int main()
{
    // creating nodes...!
    Node *head = new Node(9);
    head->next = new Node(18);
    head->next->next = new Node(108);
    head->next->next->next = new Node(432);

    int result = findLength(head, 0); // initially count is set to zero...!
    cout << "Length of the linked list: " << result << endl;

    Node *curr = head;
    while (curr != nullptr)
    {
        Node *n = curr->next;
        delete curr;
        curr = n;
    }

    return 0;
}
