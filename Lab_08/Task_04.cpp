#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int findCeil(TreeNode *root, int X)
{
    int ceil = INT_MAX;
    while (root)
    {
        if (root->val == X)
        {
            return root->val;
        }
        if (root->val < X)
        {
            root = root->right;
        }
        else
        {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int findFloor(TreeNode *root, int X)
{
    int floor = INT_MIN;
    while (root)
    {
        if (root->val == X)
        {
            return root->val;
        }
        if (root->val > X)
        {
            root = root->left;
        }
        else
        {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    insert(root, 5);
    insert(root, 11);
    insert(root, 14);
    insert(root, 7);
    insert(root, 2);

    int X;
    string choice;
    cout << "Enter the value of X: ";
    cin >> X;

    cout << "'ceil' or 'floor': ";
    cin >> choice;

    if (choice == "ceil")
    {
        int result = findCeil(root, X + 1);
        if (result == INT_MAX)
        {
            cout << "No ceil value found in the tree." << endl;
        }
        else
        {
            cout << "Ceil value: " << result << endl;
        }
    }
    else if (choice == "floor")
    {
        int result = findFloor(root, X - 1);
        if (result == INT_MIN)
        {
            cout << "No floor value found in the tree." << endl;
        }
        else
        {
            cout << "Floor value: " << result << endl;
        }
    }
    else
    {
        cout << "Invalid choice..!" << endl;
    }

    return 0;
}