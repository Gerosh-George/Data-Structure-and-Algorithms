#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int value)
{
    struct TreeNode *newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct TreeNode *buildTree(struct TreeNode *root)
{

    int data;
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    if (root == NULL)
    {
        root = createNode(data);
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void destroyTree(struct TreeNode *root)
{   if(root==NULL)
    return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);    
}

int total_nodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_count = total_nodes(root->left);
    int right_count = total_nodes(root->right);

    int total = 1 + left_count + right_count;
    return total;
}

int count_internal_nodes(struct TreeNode *root) //counts in the root node also
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    int count = 1 + count_internal_nodes(root->left) + count_internal_nodes(root->right);
    return count;
}

int total_internal_nodes(struct TreeNode *root) // subtrating 1 for the root node to get the actual count
{
    return count_internal_nodes(root) - 1;
}

int count_leaf_nodes(struct TreeNode *root)
{
    return total_nodes(root) - count_internal_nodes(root);
}

int height_of_binary_tree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftheight = height_of_binary_tree(root->left);
    int rightheight = height_of_binary_tree(root->right);

    int height = 1 + max(leftheight, rightheight);
    return height;
}

int main()
{
    struct TreeNode *root = NULL;
    printf("NOTE: -1 entry means null node\n");
    printf("PLease enter the tree data: ");
    root = buildTree(root);

    int total = total_nodes(root);
    printf("\nTotal number of nodes: %d", total);

    int a = total_internal_nodes(root);
    printf("\nTotal number of internal nodes: %d", a);

    int leaf_nodes = count_leaf_nodes(root);
    printf("\nTotal number of leaf nodes: %d", leaf_nodes);

    int h = height_of_binary_tree(root);
    printf("\nHeight of the tree: %d", h);
   
    destroyTree(root);
    free(root);
    
    printf("\nFinished!!");
}

// * INPUT: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
/** Tree will look like this:
*      1
    2     3
   4 5   6

*  OUTPUT: Total nodes:6
           Total internal nodes:2
           Total leaf nodes:3
           Height:2
*/