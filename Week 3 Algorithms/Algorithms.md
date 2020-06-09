## Algorithms

### Linear Search

The idea of the algorithm is to **iterate across the array from left to right**, searching for a specified element.

<br />

In **pseudocode**:
* Repeat, starting at the first element:
  * If the first element is what you're looking for (the target), stop.
  * Otherwise, move to the next element.
  
<br />
<br />

### Binary Search

The idea of the algorithm is to divide and conquer, **reducing the search area by half each time**, trying to find a target number.
* The array must first be **sorted**, else we cannot make assumptions about the array's contents.

<br />

In **pseudocode**:
* Repeat until the (sub)array is of size 0:
  * Calculate the *middle point* of the current (sub)array.
  * If the target is at the middle, stop.
  * Otherwise, if the target is *less than what's at the middle*, repeat, changing the *end point* to just to the left of the middle.
  * Otherwise, of the target is *greater than what's at the middle*, repeat, changing the *start point* to be just to the right of the middle.

<br />
<br />

### Bubble Sort

The idea of the algorithm is to **move higher valued elements generally towards the right** and lower value elements generally towards the left.

<br />

In **pseudocode**:
* Set swap counter to a non-zero value.
* Repeat until the swap counter is 0:
  * Reset swap counter to 0.
  * Look at each adjacent pair.
    * If *two adjacent elements are **not in order***, ***swap*** them and add one to the swap counter.
    
<br />
<br />

### Selection Sort

The idea of the algorithm is to **find the smallest unsorted element** and *add it to the end of the sorted list*.

<br />

In **pseudocode**:
* Repeat until no unsorted elements remain:
  * Search the unsorted part of the data to *find the **smallest** value*.
  * *Swap* the smallest found value *with the first element of the unsorted part*.

<br />
<br />

### Insertion Sort

The idea of the algorithm is to **build your sorted array in place**, shifting elements out of the way if necessary to make rooms as you go.

<br />

In **pseuducode**:
* Call the first element of the array *"sorted"*.
* Repeat until all elements are sorted:
  * Look at the next unsorted element. *Insert into the "sorted" portion* by shifting the requisite number of elements.

<br />
<br />

### Merge Sort

The idea of the algorithm is to **sort smaller arrays** and then **combine those arrays together** in sorted order.
* Merge sort leverages something called **recursion**.

In **pseudocode**:
* Sort the left half of the array (assuming n > 1).
* Sort the right half of the array (assuming n > 1).
* Merge the two halves sorted subarrays together.

<br />
<br />

### Summary

Algorithm   |Basic Concept   |O (Worst Case) |Ω (Best Case)
:---|:---|:---|:---
Selection Sort|Find the **smallest** unsorted element in an array and swap it with the **first** unsorted element of that array.|n^2 |n^2
Bubble Sort|Swap **adjacent pairs** of the elements if they are out of order, effectively "bubbling" larger elements to the right and smaller ones to the left.|n^2 |n
Insertion Sort|Proceed once through the array from left-to-right, **shifting** elements as necessary to insert each element into its correct place.|n^2 |n
Merge Sort|**Split** the full array into subarrays, then **merge** those subarrays back together in the correct order.|nlogn |nlogn
Linear Search|**Iterate** across the array from left-to-right, trying to find the target element.|n |1
Binary Search|Given a ***sorted*** array, **divide and conquer** by systematically eliminating half of the remaining elements in the search for the target element.|logn |1




