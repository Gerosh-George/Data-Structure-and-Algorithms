# Prim's Algorithm

Prim's algorithm finds a minimum-cost spanning tree of an edge-weighted, connected, undirected graph. The algorithm constructs the minimum-cost spanning tree of a graph by selecting edges from the graph one-by-one and adding those edges to the spanning tree. It is a greedy approach algorithm.

Time Complexity:

- Normal implemenattion (arrays): O(V^2)
- Using Binary Heap: O(E\*log(V))
- Using Fibonacci Heap: O(E+ V\*log(V))

![gMPmj](https://user-images.githubusercontent.com/62696039/100120101-95a08400-2e9d-11eb-8bed-fa75851e9274.gif)

Above image shows how the Prims' Algorithm works.

### Implementation in C:

--> <u>[Prim's Algo.c](prims_MST.c)</u>

<br>

![image](https://user-images.githubusercontent.com/62696039/100074934-55251400-2e65-11eb-8ef4-5a081ca4ef17.png)

<br>

The implemented program will determine the minimum spanning tree that can be formed in the above graph shown, along with its cost.

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/100120546-0e074500-2e9e-11eb-83fe-9befdcf3d6ec.png)
