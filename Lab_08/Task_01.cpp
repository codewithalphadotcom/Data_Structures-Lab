#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int key;
    string name;
    Node *left;
    Node *right;

    Node(int key, string name)
    {
        this->key = key;
        this->name = name;
        left = NULL;
        right = NULL;
    }

    string getString() const
    {
        return (name + " has the key " + to_string(key) + " \n");
    }
};

class BinaryTree
{
    Node *root;

    void clear(Node *node)
    {
        if (node)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(NULL) {}
    ~BinaryTree()
    {
        clear(root);
    }

    void addNode(int key, string name)
    {
        Node *newNode = new Node(key, name);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            Node *parent;
            while (true)
            {
                parent = current;
                if (key < current->key)
                {
                    current = current->left;
                    if (current == NULL)
                    {
                        parent->left = newNode;
                        return;
                    }
                }

                else
                {
                    current = current->right;
                    if (current == NULL)
                    {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    // In-Order Traversal...!
    void printTree(Node *node)
    {
        if (node != NULL)
        {
            printTree(node->left);
            cout << node->getString();
            printTree(node->right);
        }
    }

    void printTree()
    {
        printTree(root);
    }
};

int main()
{
    BinaryTree tree;
    int keys[] = {3, 2, 4, 1, 5};
    string names[] = {"Node 1", "Node 2", "Node 3", "Node 4", "Node 5"};

    for (int i = 0; i < 5; i++)
    {
        tree.addNode(keys[i], names[i]);
    }

    tree.printTree();

    return 0;
}
