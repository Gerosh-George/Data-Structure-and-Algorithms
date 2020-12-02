# Heap Data Structure

Heap DS is a special binary tree that is compulsorily a complete binary tree and can be full binary tree also. The property of the heap is that its root node will always be either minimum or maximum value present in that tree.

And according to the root node value, heap can of two types:

- Max Heap : Parent node will have value greater than its child node
- Min Heap: Parent node will have value less than its child node.

<br>

![heap types](https://user-images.githubusercontent.com/62696039/100837103-91282c80-3496-11eb-9f3b-44577b17eb6a.jpeg)

<b> Time Complexity </b>

- Inserting element: O(log(n))
- Removing element: O(log(n))
- Building heap from array (naive): O(n\*log(n))
- Building heap from array by heapify process: O(n)

The main use Heap DS is in [Priority Queue](https://github.com/Gerosh-George/Data-Structure-and-Algorithms/blob/master/Data%20Structure/Queue/PriorityQueue.cpp) and [Heap Sort](https://github.com/Gerosh-George/Data-Structure-and-Algorithms/blob/master/Algorithms/Heap%20Sort).

### Implementation in cpp:

--> <u>[Heap DS code](heap.cpp) </u>

The heap tree is a complete binary tree in nature so we can use an array representation of binary tree as we won't have any null elements in middle of the array.

In this code, we have done the implementation of Min Heap using both the processes which is creation of heap by bubbling up the node `swim()` and also by heapify, in which array containing values are sent to function `buildHeap()` which creates the entire heap.

<b> Important property when tree are represented using array: </b>

- arr[0]: the root node of tree
- arr[i]: Random node of tree
  - arr[2*i+1]: left child
  - arr[2*i+2]: right child
  - arr[(i-1)/2]: parent node

<br> <hr>

![image](https://user-images.githubusercontent.com/62696039/100837763-3c38e600-3497-11eb-9cad-155752d4e3f1.png)

Array representation of a tree.

<hr>

<img src="https://user-images.githubusercontent.com/62696039/100838153-f6c8e880-3497-11eb-8d8d-ca8a6ce02fcf.gif"  width="400">

Above Gif shows how an element is inserted in heap and bubbling up of that element takes place (which also known as swim up)

<hr>

<img src="https://user-images.githubusercontent.com/62696039/100838827-2debc980-3499-11eb-8e68-4fd12acb993c.gif"  width="400">

This GIF shows how an element is removed which is always the root node. This process is known as bubbling down of node or sink.

<hr>

![cd0d037dc0ca0e2ef1e51f5f785607c7](https://user-images.githubusercontent.com/62696039/100840644-342f7500-349c-11eb-9176-86f2a8027075.gif)

Above GIF depicts how heapify process works.

<hr>

Functions implemented:

- buildHeap()
- push()
- pop()
- print()
- len()

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/100840283-aa7fa780-349b-11eb-836e-54db28b40a71.png)

Min heap removes the smallest value from heap for each pop() call.
