# Kruskal's Algorithm

Kruskal's Algorithm finds the minimum spanning tree in a undirected graph. It is a greedy algorithm in graph theory as in each step it adds the next lowest-weight edge that will not form a cycle to the minimum spanning tree.

Time Complexity: O(E\*Log(V)) or O(E\*Log(E)) 

![480px-MST_kruskal_en](https://user-images.githubusercontent.com/62696039/100111614-44d85d80-2e94-11eb-90e1-4cd109b6ab34.gif)

Above GIF shows how the Kruskal's Algo works.

### Implementation in C:

--> <u>[Kruskal's Algo.c](kruskals_MST.c)</u>

In this implementation we have used Adjacency List to represent the graph. Also to check for cycles while adding the edge to the spanning tree we have used [Union-Find algorithm](https://www.geeksforgeeks.org/union-find/) which actually is working of Disjoint Set Data structure.

<br>

![image](https://user-images.githubusercontent.com/62696039/100074934-55251400-2e65-11eb-8ef4-5a081ca4ef17.png)

<br>

The implemented program will determine the minimum spanning tree that can be formed in the above graph shown, along with its cost.

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/100113178-0d6ab080-2e96-11eb-85ed-b2a2491bb926.png)
