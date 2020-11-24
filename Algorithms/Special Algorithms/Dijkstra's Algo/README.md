# Dijkstra's Algorithm

Dijkstra's Algo is a greedy approach which helps to find the shortest distance/path from a source vertex to a destination vetex. (Estimates the Single source shortest path along with its distance)

![Dijkstra](https://user-images.githubusercontent.com/62696039/100074887-49d1e880-2e65-11eb-8273-8b5dd1c7ef19.gif)

Above GIF depicts how the Dijkstra Algorithm actually works.

Time Complexity:

- Normal Implementation (using arrays): O(V^2)
- Using Min heap: O(E\*log(V))
- Using Fibonacci Heap: O(E + V\*Log(V))

[Note: E-no. of edges, V-no. of vertices/nodes]

<b> [Visualization of Dijkstra's Algo](https://www.cs.usfca.edu/~galles/visualization/Dijkstra.html)
</b>

### Implementation in C:

--> <u>[Dijkstra.c](dijkstra.c) </u>

In this program,we have done a normal implementation using arrays to keep track visited,unvisited nodes and shortest distance.

<br>

![image](https://user-images.githubusercontent.com/62696039/100074934-55251400-2e65-11eb-8ef4-5a081ca4ef17.png)

<br>

Above picture depicts a graph of 6 cities connected. The dijkstra's algo that we implemented in C language will estimate the shortest path and distance from city 'B' to all the other cities.

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/100108187-8535dc80-2e90-11eb-974b-3f0f2928b3a4.png)
