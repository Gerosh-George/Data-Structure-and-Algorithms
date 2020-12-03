//Binary Tree

#include <iostream>
#include <vector>
using namespace std;

//Node Class
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// recursively builds the tree from root node.
TreeNode *BuildTree(TreeNode *root)
{
    int data;
    cin >> data;

    //Base Case
    if (data == -1)
    {
        return NULL;
    }

    //Recursive Case
    if (root == NULL)
    {
        root = new TreeNode(data);
    }

    root->left = BuildTree(root->left);
    root->right = BuildTree(root->right);

    return root;
}

void inOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// counts the num of nodes in the binary tree
int countNodes(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    int totalCount = leftCount + 1 + rightCount;
    return totalCount;
}

int sumOfNodes(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    int totalSum = leftSum + root->data + rightSum;

    return totalSum;
}

// searches in binary tree to find the key
bool search(TreeNode *root, int key)
{

    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    bool leftSearch = search(root->left, key);
    bool rigthSearch = search(root->right, key);

    if (leftSearch or rigthSearch)
    {
        return true;
    }

    return false;
}

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    int depth = max(leftDepth, rightDepth) + 1;
    return depth;
}

// returns the vector with values sorted in acsending order
// the tree needs to be a binary search tree for this to work
void sorted(TreeNode *root, vector<int> &res)
{

    if (root == NULL)
    {
        return;
    }

    sorted(root->left, res);
    res.push_back(root->data);
    sorted(root->right, res);
}

// searches the key value in the binary search tree
bool BSTsearch(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == k)
    {
        return true;
    }

    if (root->data > k)
    {
        return BSTsearch(root->left, k);
    }
    else
    {
        return BSTsearch(root->right, k);
    }
}

// checks if the tree build is a BST or not.
bool isBST(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->left and root->data < root->left->data)
        return false;
    if (root->right and root->data > root->right->data)
        return false;

    bool left = isBST(root->left);
    bool right = isBST(root->right);

    return left and right;
}

int main()
{
    TreeNode *root = NULL;
    cout << "Please Enter the tree data: ";
    root = BuildTree(root);

    cout << "INORDER: ";
    inOrder(root);

    cout << endl
         << "PREORDER: ";
    preOrder(root);

    cout << endl
         << "POSTORDER: ";
    postOrder(root);

    cout << endl
         << "TOTAL NUMBER OF NODES: ";
    cout << countNodes(root) << endl;

    cout << "Total Sum: ";
    cout << sumOfNodes(root) << endl;

    cout << "Is 5 present in the tree?: ";
    cout << boolalpha << search(root, 5) << endl;

    cout << "DEPTH: ";
    cout << maxDepth(root) << endl;

    cout << "Is the binary tree a binary search tree?: ";
    cout << boolalpha << isBST(root) << endl;

    if (isBST(root))
    {

        cout << "Third smallest value in BST: ";
        int k = 3;
        vector<int> res;
        sorted(root, res);
        int value = res[k - 1];
        cout << value << endl;

        cout << "Is 5 present in the tree? (BSTsearch): ";
        cout << boolalpha << BSTsearch(root, 5) << endl;
    }

    return 0;
}

// * Sample Input: 4 2 1 -1 -1 -1 6 5 -1 -1 8 -1 -1