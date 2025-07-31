#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int val)
    {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int getBalance(Node *node)
{
    if (node == nullptr)
        return 0;
    return (height(node->left) - height(node->right));
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;

    return y;
}

Node *insert(Node *node, int key)
{

    if (node == nullptr)
    {
        return new Node(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }
    node->height = (height(node->left) > height(node->right) ? height(node->left) : height(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root = nullptr;

    int keys[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        root = insert(root, keys[i]);
    }

    cout << "Inorder Traversal of the Tree: ";
    inOrder(root);
    cout << endl;

    return 0;
}