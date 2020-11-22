# Queue

A Queue is data structure that follows the principle of First In First Out (FIFO).

You can visualise a queue data structure like a queue of people standing in front of ticket counter. The queue DS follows the exact same properties of queue in real life. The item that is added first will be removed first and other items pushed will be added to rear end.

- Pushing in Queue is known as Enqueue
- Popping in Queue is known as Dequeue

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

--> <u> [queue.cpp](queue.cpp) </u>

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

<u> [printer.c](printer.c) </u>

One of the application of Queue is in scheduling of printer. When printer is in use other people needs to wait in queue. This scenario is stimulated using Queue DS in this program using C language.

Output:

<img width="213" alt="Capture" src="https://user-images.githubusercontent.com/62696039/99901859-b7eca300-2cdf-11eb-9d3a-b96aa7059dce.PNG">

Here #12 was printing so #15 was in line. Afterwards when #13 came #15 was in printing state and #13 had to be in the line.

<hr>
