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

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *node, int key)
{
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool find_kth_smallest(Node *node, int &k, int &result)
{
    if (node == nullptr)
    {
        return false;
    }
    if (find_kth_smallest(node->left, k, result))
    {
        return true;
    }
    k--;
    if (k == 0)
    {
        result = node->key;
        return true;
    }

    return find_kth_smallest(node->right, k, result);
}

bool findKthLargest(Node *node, int &k, int &result)
{
    if (node == nullptr)
        return false;

    if (findKthLargest(node->right, k, result))
        return true;

    k--;
    if (k == 0)
    {
        result = node->key;
        return true;
    }

    return findKthLargest(node->left, k, result);
}

void printTreeHeights(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    cout << "Left Subtree Height: " << leftHeight << endl;
    cout << "Right Subtree Height: " << rightHeight << endl;
}

int main()
{
    Node *root = nullptr;
    int keys[] = {4, 8, 17, 9, 11, 2};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, keys[i]);
    }

    int k = 3;
    int kth = k;
    int kthSmallest = -1;
    cout << endl;
    if (find_kth_smallest(root, k, kthSmallest))
    {
        cout << "The " << kth << "-th smallest element is " << kthSmallest << endl;
    }
    else
    {
        cout << kth << "-th smallest element does not exist." << endl;
    }

    k = 3;
    kth = k;
    int kthLargest = -1;
    if (findKthLargest(root, k, kthLargest))
    {
        cout << "The " << kth << "-th largest element is " << kthLargest << endl;
    }
    else
    {
        cout << kth << "-th largest element does not exist." << endl;
    }
    cout << endl;

    printTreeHeights(root);
    cout << endl;

    return 0;
}