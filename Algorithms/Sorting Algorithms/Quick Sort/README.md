# Quick Sort

Quick Sort ia another advanced sorting algorithm that uses the approach of divide and conquer.

It uses a technique known as `partition` and so sometimes also known as partition sort. It picks an element as pivot and partitions the given array around the picked pivot.

This pivot element can be taken in different manner like the first element, or the last or even random or the median element. 

The key function in this Algo is partition() function which places the pivot element in its perfect position.

Time Complexity: 
- Worst Case: O(n^2)
- Best Case: O(n log(n))

<br>

![PleasantCloseEyelashpitviper-size_restricted](https://user-images.githubusercontent.com/62696039/100057903-5ac32f80-2e4e-11eb-96eb-ca8f4674bfbc.gif)

Above GIF shows how a Quick Sort Algo works.
<hr>

### Implementation in C:

--> [Quick Sort.c](quicksort.c)

In this implementation, pivot element is taken as the first element in subset array.

OUTPUT:

![image](https://user-images.githubusercontent.com/62696039/100058470-56e3dd00-2e4f-11eb-88bb-1745b57b258a.png)


