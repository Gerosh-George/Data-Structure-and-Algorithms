# Selection Sort

Selection Sort is a simple sorting algorithm. This algorithm sorts an array by repeatedly finding minimum element from unsorted part and putting it at the beginning.<br>

The algorithm maintains two subarrays in a given array.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1) The subarray which is already sorted.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2) Remaining subarray which is sorted.<br>

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

Time Complexity: Best Case: Ω(n) Average Case: θ(n<sup>2</sup>) Worst Case: O(n<sup>2</sup>)

<br><hr>

## Working of the Algorithm

<img src="https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif" style="margin-left:42%">



<img src="https://user-images.githubusercontent.com/68146112/100702693-2ad4d880-33c8-11eb-82d1-51e41efd0a2b.gif" style="margin-left:13%">
<hr>


## Implementation in cpp

<a href="selectionsort.cpp">Selection Sort Code</a>

<br><hr>

## Output

<img src="https://user-images.githubusercontent.com/68146112/100702836-67083900-33c8-11eb-8897-972a46d6b93e.png" style="margin-left:10%">
