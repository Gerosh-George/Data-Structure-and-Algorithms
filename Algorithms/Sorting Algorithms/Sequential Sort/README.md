# Sequential Sort

Sequential sort is simple sorting algorithm. This sorting algorithm is kinda a mix of selection and bubble sort. It finds the minimum element and places it at the front of the array but the way in which it does is little different. It swaps current position element with any value that is smaller than current value which are placed ahead of it in the array and does this till the entire array is traversed. Thus in the end at current position the right minimum element will be placed.<br>

The algorithm maintains two subarrays in a given array.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1) The subarray which is already sorted.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2) Remaining subarray which is sorted.<br>

Time Complexity: θ(n<sup>2</sup>) in all 3 cases (worst,average and best)

## Implementation in cpp

<a href="sequentialsort.cpp">Sequential Sort Code</a>

<br><hr>

## Output

<br>

<img src="https://user-images.githubusercontent.com/68146112/100762164-ad39b880-3419-11eb-8468-b9b780d54258.png" style="margin-left:10%">

<br><br>

Here index position are also printed to show which two elements are exactly swapped during the execution of this algorithm. Comparing this with [selection](https://github.com/Gerosh-George/Data-Structure-and-Algorithms/tree/master/Algorithms/Sorting%20Algorithms/Selection%20Sort) and [bubble](https://github.com/Gerosh-George/Data-Structure-and-Algorithms/tree/master/Algorithms/Sorting%20Algorithms/Bubble%20Sort) sort algorithm output you can easily spot the difference!
