# Binary Search Tree

Its a special binary tree which has a specific nature in which nodes are inserted into it.

These properties needs to maintained for a binary tree to be BST in nature:

- Parent node value is always greater than equal to its left child node.
- Parent node value is always lesser than equal to its rigt child node.

  <div style="text-align: center;">OR</div>

- Each and every node's value in a BST will be greater than all the values present in the left sub tree and lesser than every value present in the right sub tree.

![image](https://user-images.githubusercontent.com/62696039/101044060-f9fdca80-35a4-11eb-9153-54d016aafc8d.png)

# Implementation of BST in C:

--> <u>[BST Code(1)](binarysearchtree.c)</u>

Very simple implementation of BST is done in C with all different kinds of operations done on it.

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/101044724-b0fa4600-35a5-11eb-8cd9-752cda4be3d3.png)

Inorder traversal of BST always produces ascending order of the elements in the tree.

<hr>

--> <u>[BST Code(2)](BST.c)</u>

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/101045490-54e3f180-35a6-11eb-9a9f-f76ca1d507b0.png)

<hr>

## Different Traversal Technique used on Binary Tree and BST:

Depth First Search traversals:

- Inorder:

<b> Left-Root-Right </b>

![Inorder-traversal](https://user-images.githubusercontent.com/62696039/101048095-5f06ef80-35a8-11eb-8718-59097e8759e6.gif)

- Preorder:

<b> Root-Left-Right </b>

![Preorder-traversal](https://user-images.githubusercontent.com/62696039/101048200-734aec80-35a8-11eb-9fac-0497c461dd1e.gif)

- Postorder:

<b> Left-Right-Root </b>

![Postorder-traversal](https://user-images.githubusercontent.com/62696039/101048276-8067db80-35a8-11eb-905a-dc3a91c8f68d.gif)

<hr>

Breadth First Search Traversal:

- Level order:

All the nodes in each level are displayed in order.

![1_3NKvODZparRFVKEwtVmrkw](https://user-images.githubusercontent.com/62696039/101048443-a1303100-35a8-11eb-90a6-fcae5999b600.gif)

<hr>
