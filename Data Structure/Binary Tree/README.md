# Binary Tree

First of all a tree is type of graph in which there are no cycles. And a binary tree is a non linear data structure in which each node has atmost 2 children.

Binary Tree types:

- Full Binary Tree: Its a special kind of a binary tree that has either zero children or two children.

- Complete Binary Tree: Its another specific type of binary tree in which nodes have exactly two child nodes except the last level where nodes resides at the left side.

[ Note: An easy way to identify a complete binary tree is by making the array representation of the tree. If the array is filled without any null values in middle then the tree is complete in nature ]

<b> Time Complexity: </b>

- Insertion of element: θ(log(n))
- Deletion of element: θ(log(n))
- Searching for value: θ(log(n))
- Update value: θ(log(n))

Worst Case for all these operation is O(n) when the binary tree is very skewed which usually does not occur in practical usage.

<hr>

The only operation that is little bit tricky to do on a binary tree/BST is deletion as there can be three cases. These are:

- Case 1: Node deleted is a leaf node

  ![giphy](https://user-images.githubusercontent.com/62696039/101055121-a8a70880-35af-11eb-8c3f-30207d53cb93.gif)

- Case 2: Node deleted is a node having one child

  ![giphy (1)](https://user-images.githubusercontent.com/62696039/101055192-b8bee800-35af-11eb-8f43-a38d3cd89220.gif)

- Case 3: Node deleted is a node having bolth child.

  ![giphy (2)](https://user-images.githubusercontent.com/62696039/101055323-cc6a4e80-35af-11eb-811d-ab7adfedf98d.gif)

[GIF reference](https://dev.to/jenshaw/deleting-nodes-in-binary-search-trees-4nhm)

<hr>

### Implementation in CPP:

In this implementation we have used `TreeNode` object which has the property of data, left and right pointers. Recursive approach is used to build the tree. Most of operation that can be done on binary tree are implemented in the code like inorder, preorder, postoder traversal.

--> <u>[Binary Tree code](Tree.cpp) </u>

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/101026697-39281d80-359d-11eb-8456-ec2d3acce8c1.png)

<hr>

Tree inputs can be taken in various format. In this code implementation it assumed that first left tree will be build and `-1` will mean as empty/null node in the tree. For example, 1 2 3 means 1 is parent node, 2 is left child node and 3 is right child node. 1 2 -1 means 1 is parent node and 2 is left child node and there is no right child node as -1 is given.

<hr>

![image](https://user-images.githubusercontent.com/62696039/101026896-77254180-359d-11eb-9b0d-6df85d8683b6.png)

<hr>

### Implementation in C:

--> <u>[Binary Tree code](binarytree.c) </u>

Class declaration is not there in C so struct is used to make an object of `Node`. Rest of the things are similar to what is done in cpp.

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/101029366-0a12ab80-359f-11eb-8c98-5e038d8f6129.png)

<hr>
