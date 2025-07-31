#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    Node *insert(Node *node, int value, string &position)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->value)
        {
            if (node->left == nullptr)
            {
                position = "Left Child";
            }
            node->left = insert(node->left, value, position);
        }
        else if (value > node->value)
        {
            if (node->right == nullptr)
            {
                position = "Right Child";
            }
            node->right = insert(node->right, value, position);
        }

        return node;
    }

    Node *search(Node *node, int value)
    {
        if (node == nullptr || node->value == value)
        {
            return node;
        }

        if (value < node->value)
        {
            return search(node->left, value);
        }
        else
        {
            return search(node->right, value);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        string position = "";
        Node *foundNode = search(root, value);
        if (foundNode != nullptr)
        {
            cout << value << " already exists in the tree." << endl;
            return;
        }

        root = insert(root, value, position);
        if (root->value == value)
        {
            cout << "Inserted " << value << " as Root." << endl;
        }
        else
        {
            cout << "Inserted " << value << " as " << position << endl;
        }
    }

    bool search(int value)
    {
        return (search(root, value) != nullptr);
    }
};

int main()
{
    BinarySearchTree bst;

    bst.insert(4);
    bst.insert(9);
    bst.insert(2);
    bst.insert(7);

    int valueToSearch = 2;

    if (!bst.search(valueToSearch))
    {
        bst.insert(valueToSearch);
    }
    else
    {
        cout << valueToSearch << " already exists in the tree." << endl;
    }

    return 0;
}
