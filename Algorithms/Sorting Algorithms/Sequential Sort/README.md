# Sequential Sort

Sequential sort is simple sorting algorithm. This algorithm sorts an array by repeatedly finding minimum element from unsorted part and putting it at the beginning.<br>

The algorithm maintains two subarrays in a given array.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1) The subarray which is already sorted.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2) Remaining subarray which is sorted.<br>

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

Time Complexity: θ(n<sup>2</sup>) in all 3 cases (worst,average and best)

## Implementation in cpp

<a href="sequentialsort.cpp">Sequential Sort Code</a>

<br><hr>

## Output

<img src="https://user-images.githubusercontent.com/68146112/100762164-ad39b880-3419-11eb-8468-b9b780d54258.png" style="margin-left:10%">