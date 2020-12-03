#include <stdio.h>
#include <stdlib.h>

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

struct TreeNode *find_parent_node_in_BST(struct TreeNode *root, int value)
{
    if (value < root->data && root->left != NULL)
    {
        root = find_parent_node_in_BST(root->left, value);
    }
    else if (value > root->data && root->right != NULL)
    {
        root = find_parent_node_in_BST(root->right, value);
    }

    return root;
}

struct TreeNode *buildBST(struct TreeNode *root)
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

    else
    {
        struct TreeNode *parent_node = find_parent_node_in_BST(root, data);

        if (data <= parent_node->data)
        {
            parent_node->left = createNode(data);
        }
        else
        {
            parent_node->right = createNode(data);
        }
    }

    buildBST(root);
    return root;
}

void destroyTree(struct TreeNode *root)
{
 if(root==NULL)
    return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);    
}

void inOrder(struct TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main()
{
    printf("NOTE: -1 entry means end of the list\n");
    struct TreeNode *root = NULL;
    printf("PLease enter the BST data: ");
    root = buildBST(root);

    printf("\nInorder Traversal: ");
    inOrder(root);

    printf("\nPreorder Traversal: ");
    preOrder(root);

    printf("\nPostorder Traversal: ");
    postOrder(root);

    destroyTree(root);
    free(root);

    printf("\nFinished!!");
}

// * Sample Input: 6 3 2 4 8 7 9 -1