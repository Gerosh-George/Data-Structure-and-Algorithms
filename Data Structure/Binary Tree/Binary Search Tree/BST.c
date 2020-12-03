#include <stdio.h>
#include <stdlib.h>

int len = 0;

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
    len++;
    buildBST(root);
    return root;
}

void destroyTree(struct TreeNode *root)
{
    if (root == NULL)
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

struct TreeNode *search(struct TreeNode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
        return root;

    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int form_inorder_list(struct TreeNode *root, int *arr, int i)
{
    if (root == NULL)
    {
        return i;
    }

    i = form_inorder_list(root->left, arr, i);
    arr[i] = root->data;
    i++;
    i = form_inorder_list(root->right, arr, i);
}

void find_predecessor_and_successor(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return;
    }

    int list[len];
    form_inorder_list(root, list, 0);
    int index = -1;

    for (int i = 0; i < len; i++)
    {
        if (val == list[i])
        {
            index = i;
        }
    }

    if (index == -1)
    {
        printf("Value not present in BST!\n");
    }
    else
    {
        if (index - 1 == -1)
            printf("Predecessor: None\n");
        else
            printf("Predecessor: %d\n", list[index - 1]);

        if (index + 1 == len)
            printf("Successor: None");
        else
            printf("Successor: %d\n", list[index + 1]);
    }
}

struct TreeNode *minValueNode(struct TreeNode *root)
{
    struct TreeNode *current = root;
    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

struct TreeNode *delete_key(struct TreeNode *root, int key)
{

    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
        root->left = delete_key(root->left, key);
    else if (key > root->data)
        root->right = delete_key(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct TreeNode *node = root->right;
            free(root);
            return node;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *node = root->left;
            free(root);
            return node;
        }

        struct TreeNode *node = minValueNode(root->right);
        root->data = node->data;

        root->right = delete_key(root->right, node->data);
    }

    return root;
}

int height(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
    {

        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printGivenLevel(struct TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOder(struct TreeNode *root)
{
    int h = height(root);
    int i;
    printf("Level order: ");
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
    printf("\n");
}

int main()
{
    printf("NOTE: -1 entry means end of the list\n");
    struct TreeNode *root = NULL;
    printf("PLease enter the BST data: ");
    root = buildBST(root);

    printf("\nInorder Traversal: ");
    inOrder(root);

    //SEARCH
    struct TreeNode *node = NULL;
    printf("\n\nEnter the value to be searched: ");
    int key = 0;
    scanf("%d", &key);

    node = search(root, key);
    if (node != NULL)
    {
        printf("Element Found!!\n");
        printf("Addess of node having value %d is %p", key, &node);
    }
    else
    {
        printf("Element Not Found!");
    }

    //Predecessor and Successor
    printf("\n\nEnter the value whose predecessor and successor needs to be found: ");
    int value = 0;
    scanf("%d", &value);
    find_predecessor_and_successor(root, value);

    //DELETE
    printf("\nEnter the Values to delete (-1 means list end): ");
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num == -1)
            break;
        delete_key(root, num);
        levelOder(root);
    }

    destroyTree(root);
    free(root);
    printf("\nFinished!");
}

// * Sample Input: 11 66 6 9 40 28 5 88 125 90 -1