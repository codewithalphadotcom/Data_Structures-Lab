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

    // add the nodes recursively...
    void addNodeRec(Node *&current, Node *newNode)
    {
        if (current == NULL)
        {
            current = newNode;
        }
        else
        {
            if (newNode->key < current->key)
            {
                addNodeRec(current->left, newNode);
            }
            else
            {
                addNodeRec(current->right, newNode);
            }
        }
    }

    bool isCompleteTree(Node *node, int index, int numberNodes)
    {
        if (node == NULL)
            return true;

        if (index >= numberNodes)
            return false;

        return (isCompleteTree(node->left, 2 * index + 1, numberNodes) &&
                isCompleteTree(node->right, 2 * index + 2, numberNodes));
    }

    int countNodes(Node *node)
    {
        if (node == NULL)
            return 0;
        return (1 + countNodes(node->left) + countNodes(node->right));
    }

    bool isFullTree(Node *node)
    {
        if (node == NULL)
        {
            return true;
        }

        if (node->left == NULL && node->right == NULL)
        {
            return true;
        }

        if (node->left != NULL && node->right != NULL)
        {
            return (isFullTree(node->left) && isFullTree(node->right));
        }
        return false;
    }

    void deleteNode(Node *&node)
    {
        if (node)
        {
            deleteNode(node->left);
            deleteNode(node->right);
            delete node;
            node = NULL;
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
        addNodeRec(root, newNode);
    }

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

    bool isComplete()
    {
        int nodeCount = countNodes(root);
        return isCompleteTree(root, 0, nodeCount);
    }

    bool isFull()
    {
        return isFullTree(root);
    }

    void makeFull()
    {
        deleteNode(root);
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

    int newKeys[] = {7, 6, 8};
    string newNames[] = {"Node 6", "Node 7", "Node 8"};

    for (int i = 0; i < 3; i++)
    {
        tree.addNode(newKeys[i], newNames[i]);
    }
    tree.printTree();

    if (!tree.isComplete())
    {
        cout << "The tree is not complete." << endl;
        tree.makeFull();
    }
    else
    {
        cout << "The tree is complete." << endl;
    }

    if (!tree.isFull())
    {
        cout << "The tree is not full." << endl;
        tree.makeFull();
    }
    else
    {
        cout << "The tree is full." << endl;
    }

    return 0;
}