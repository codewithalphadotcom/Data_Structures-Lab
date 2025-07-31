#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode *root, int arr[], int &index)
{
    if (!root)
    {
        return;
    }
    inorderTraversal(root->left, arr, index);
    arr[index++] = root->value;
    inorderTraversal(root->right, arr, index);
}

void mergeArrays(int arrOne[], int arrTwo[], int sizeOne, int sizeTwo, int merged[])
{
    int i = 0, j = 0, k = 0;
    while ((i < sizeOne) && (j < sizeTwo))
    {
        if (arrOne[i] < arrTwo[j])
        {
            merged[k++] = arrOne[i++];
        }
        else
        {
            merged[k++] = arrTwo[j++];
        }
    }
    while (i < sizeOne)
    {
        merged[k++] = arrOne[i++];
    }
    while (j < sizeTwo)
    {
        merged[k++] = arrTwo[j++];
    }
}

TreeNode *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = start + (end - start) / 2;

    TreeNode *node = new TreeNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);
    return node;
}

TreeNode *mergeBSTs(TreeNode *rootOne, TreeNode *rootTwo, int sizeOne, int sizeTwo)
{
    int *arrOne = new int[sizeOne];
    int *arrTwo = new int[sizeTwo];
    int indexOne = 0, indexTwo = 0;

    inorderTraversal(rootOne, arrOne, indexOne);
    inorderTraversal(rootTwo, arrTwo, indexTwo);

    int *mergedArray = new int[sizeOne + sizeTwo];
    mergeArrays(arrOne, arrTwo, sizeOne, sizeTwo, mergedArray);

    TreeNode *mergedBST = sortedArrayToBST(mergedArray, 0, sizeOne + sizeTwo - 1);

    delete[] arrOne;
    delete[] arrTwo;
    delete[] mergedArray;

    return mergedBST;
}

void printTree(TreeNode *root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

int main()
{

    TreeNode *BST_1 = new TreeNode(5);
    BST_1->left = new TreeNode(3);
    BST_1->right = new TreeNode(6);
    BST_1->left->left = new TreeNode(2);
    BST_1->left->right = new TreeNode(4);

    TreeNode *BST_2 = new TreeNode(2);
    BST_2->left = new TreeNode(1);
    BST_2->right = new TreeNode(3);
    BST_2->right->right = new TreeNode(7);
    BST_2->right->right->left = new TreeNode(6);

    int sizeOne = 5;
    int sizeTwo = 5;

    TreeNode *mergedBST = mergeBSTs(BST_1, BST_2, sizeOne, sizeTwo);

    cout << "\nInorder traversal of the merged BST: ";
    printTree(mergedBST);
    cout << endl;

    return 0;
}
