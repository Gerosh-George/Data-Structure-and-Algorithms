# Insertion Sort

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.<br>
The array is virtually split into a sorted and an unsorted part.<br>
Values from the unsorted part are picked and placed at the correct position in the sorted part.
<br>
<hr>

## Algorithm

To sort an array of size n in ascending order:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1: Iterate from arr[1] to arr[n] over the array.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2: Compare the current element (key) to its predecessor.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.<br>
<br>
<hr>

Time Complexity: Best Case: Ω(n) Average Case: θ(n<sup>2</sup>) Worst Case: O(n<sup>2</sup>)

<br><hr>

## Working of the Algorithm

<img src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif" style="margin-left:13%">



<img src="https://user-images.githubusercontent.com/68146112/100774265-e547f800-3427-11eb-8d2a-8be8c0695573.gif" style="margin-left:13%; height: 200px;">
<hr>


## Implementation in cpp

<a href="insertionsort.cpp">Insertion Sort Code</a>

<br><hr>

## Output

<img src="https://user-images.githubusercontent.com/68146112/100774473-1e806800-3428-11eb-8b16-a42760fefacc.png" style="margin-left:10%">
<img src="https://user-images.githubusercontent.com/68146112/100774542-335cfb80-3428-11eb-98cb-e3d0839eca31.png" style="margin-left:10%">
