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

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        if ((root->left == nullptr) ||
            (root->right == nullptr))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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

void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

Node *search(Node *root, int key)
{
    if (root == nullptr || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main()
{
    Node *root = nullptr;

    int keys[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        root = insert(root, keys[i]);
    }

    cout << "Inorder Traversal of the Tree before Search and Insert: ";
    inOrder(root);
    cout << endl
         << endl;

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    Node *res = search(root, key);

    if (res != nullptr)
    {
        cout << "Key " << key << " found in the tree." << endl;
    }
    else
    {
        cout << "Key " << key << " not found in the tree!" << endl;

        cout << "Inserting the key " << key << " in the tree." << endl;
        root = insert(root, key);
        cout << "Inorder Traversal of the Tree after Search and Insert: ";
        inOrder(root);
        cout << endl;
    }

    return 0;
}