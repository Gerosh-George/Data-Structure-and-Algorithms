# Queue

A Queue is data structure that follows the principle of First In First Out (FIFO).

You can visualise a queue data structure like a queue of people standing in front of ticket counter. The queue DS follows the exact same properties of queue in real life. The item that is added first will be removed first and other items pushed will be added to rear end.

- Pushing in Queue is known as Enqueue
- Popping in Queue is known as Dequeue

![image](https://user-images.githubusercontent.com/62696039/99903423-423a0480-2cea-11eb-918a-a607dac869b3.png)

There are 4 main variations of Queue:

- Normal Queue
- Deque (Double ended Queue)
- Circular Queue
- Priority Queue

<b> Time Complexity (Array Implementation) </b>

- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

Auxiliary Space: O(N)

### Implementation in C++:

--> <u> [Queue.cpp](Queue.cpp) </u>

Generic programming approach is used to implement the Queue DS. This is a base implementation of a normal Queue.

Function implemented:

- enqueue()
- dequeue()
- peek()
- print()
- len()

Output:

![image](https://user-images.githubusercontent.com/62696039/99901061-e36c8f00-2cd9-11eb-8441-17c62b1522bd.png)

<hr>

### Implementation in C (printer problem):

--> <u> [printer.c](printer.c) </u>

One of the application of Queue is in scheduling of printer. When printer is in use other people needs to wait in queue. This scenario is stimulated using Queue DS in this program using C language.

Output:

<img width="213" alt="Capture" src="https://user-images.githubusercontent.com/62696039/99901859-b7eca300-2cdf-11eb-9d3a-b96aa7059dce.PNG">

Here #12 was printing so #15 was in line. Afterwards when #13 came #15 was in printing state and #13 was put as next in the schedule.

<hr>

### Deque (Double Ended Queue)

Deque is a special type of queue in which the insertion and deletion can take place at both the ends of the queue.

Its like a combination of stack and queue DS. Deque data structure supports clockwise and anticlockwise rotations in O(1) time which can be useful in certain applications.

![image](https://user-images.githubusercontent.com/62696039/99929280-a4d6e300-2d72-11eb-87d3-748e036f70fc.png)

#### Implementation in C:

---> <u> [deque.c](deque.c) </u>

In this program, Deque is implemented using a static array of fixed size (10) which has a global scope. The extra functions that deque has are:

- enqueue_front()
- enqueue_rear()
- dequeue_front()
- dequeue_rear()
- get_front()
- get_rear()

Time complexity of all these operations are O(1) using arrays.

Output:

![image](https://user-images.githubusercontent.com/62696039/99929162-28dc9b00-2d72-11eb-8319-ebce4e2b2844.png)

<hr>

### Circular Queue

The simple queue has a limitation that it can't fill the slot in the front of queue when some of the elements are dequeued. This is overcomed by using a circualr queue instead. It is pretty simple just assume the linear array is now circular in shape and implement the properties of a normal queue.

![image](https://user-images.githubusercontent.com/62696039/99932097-1025b280-2d7d-11eb-80c8-524e66667cb7.png)

### Implementation in C:

--> <u>[Circular Queue.c](circular_queue.c) </u>

In this implementation instead of declaring a global array we have used `struct Queue` to make an object/structure of the queue.

[Learn more about struct](https://www.geeksforgeeks.org/structures-c/)

The main logic of circular queue is:

rear = (rear + 1) % SIZE; <br>
front = (front + 1) % SIZE;

These two statements gives the array a circular nature.

Output:

![image](https://user-images.githubusercontent.com/62696039/99931409-6ba27100-2d7a-11eb-88a7-1db2e6abd760.png)

<hr>

### Priority Queue

Priority Queue is a special type of queue which pops/removes an element according to the priority of that element with respect to others present in it. 

Priority Queue can be implemented using arrays or linklist but then time complexity becomes O(n) and extra additional space is also needed for array rearrangement.

The ideal way of implementing Priority Queue is using another underlying DS known as Heaps, more specifically Min Binary Heap  or Max Binary Heap.

![PQ](https://user-images.githubusercontent.com/62696039/99975317-155c1f00-2dc8-11eb-96ec-79759029d827.jpg)


Here max element is given priority so max heap keeps the largest element at the root of the heap so that it can be popped out when poll() is called on it.

![image](https://user-images.githubusercontent.com/62696039/99971435-26566180-2dc3-11eb-8a65-c716643d9f12.png)

These are two types of heap invariant.

[ poll() pops out the element with the appropriate priority ]

Time Complexity (Min/Max Binary Heap Implementation ) :
- BuildPQ(): O(n)  [ Min binary heap construction ]
- add(): O(log(n))
- poll(): O(log(n))
- contains(): O(1)
- peek(): O(1)
- remove(): O(log(n))
- len(): O(1)
- isEmpty(): O(1)


### Implementation in C++:

Implementation of priority queue in cpp is little tricky. 
So watch this [youtube tutorial](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=5492s) which will help you too understand how everything ties up.

For this implementation you will need know a little about the [STL](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/) of C++ and heap properties.

Map container is used which acts like hash table to help optimise the operations like remove() and contains().

--> <u> [Priority Queue.cpp](PriorityQueue.cpp) </u>


![image](https://user-images.githubusercontent.com/62696039/99972135-2a36b380-2dc4-11eb-9be7-25d2f203bc59.png)

<hr>

