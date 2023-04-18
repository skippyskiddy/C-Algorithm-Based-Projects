# Sort Analysis Data

## Results Table

### Table
| N      | Bubble    | Selection | Insertion | Merge    | Quick    |
|--------|-----------|-----------|-----------|----------|----------|
| 10     | 0.000002  | 0.000002  | 0.000002  | 0.000003 | 0.000002 |
| 100    | 0.000033  | 0.000026  | 0.000027  | 0.000017 | 0.000011 |
| 500    | 0.000717  | 0.000184  | 0.000179  | 0.000036 | 0.000063 |
| 1000   |  0.003246 |  0.001662 | 0.001807  | 0.000190 | 0.000134 |
| 5000   |  0.057737 |  0.016358 | 0.019031  | 0.000450 | 0.000763 |
| 10000  | 0.197509  | 0.084571  | 0.095893  | 0.002400 | 0.001646 |
| 50000  | 5.432307  | 1.603331  | 1.876904  | 0.012144 | 0.008870 |
| 80000  | 14.082845 | 4.107506  | 4.796389  | 0.019104 | 0.013879 |
| 10000  | 22.083705 | 6.327434  | 7.407804  | 0.022271 | 0.015091 |
| 150000 | 50.184131 | 14.245974 | 16.833112 | 0.030486 | 0.021571 |
| 200000 | 89.795233 | 25.201828 | 30.032244 | 0.039134 | 0.028335 |


## BigO Analysis  / Questions

### 1. Build a line chart

Below are three different line charts with different maximums for a better understanding of the difference in the growth of the algorithms. 
<p align="center">
<img src="https://github.com/Spring23-CS5008-BOS-Lionelle/homework-05-skippyskiddy/blob/main/0.5_max.png?raw=true" width=60% height=60%>
  
<p align="center">
<img src="https://user-images.githubusercontent.com/109384275/224594436-c0653615-200c-4512-9cc7-ec819e32dd77.png" width=60% height=60%>
  
<p align="center">
<img src="https://user-images.githubusercontent.com/109384275/224594486-7f36c272-9a62-44d7-949c-9a434325b373.png" width=60% height=60%>


### 2. Convinced?

Yes- the growth of each algorithm's runtime aligns with the assigned time complexity of each sort. As expected, bubble sort is extremely inefficent, and selection sort and insertion sort are relatively inefficent. It was surprising to see the similarity in the growth between selection and insertion sort, but this makes sense because selection sort requires a complete pass through the entire “unsorted” subarray on each iteration of the outer loop, whereas insertion sort can only have to pass through a few elements before locating the correct position of the current element. Unsurprisingly, quick sort and merge sort were extremely efficent, even though merge sort is more efficent because it has fewer comparisons, quick sort is faster in practice. In a worst case scenario, merge sort would be faster, but in this case, quick sort was faster. 


### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do. 
  
  
 | Algorithm      | Best Case  | Worst Case | Average Case |
|----------------|------------|------------|--------------|
| Bubble Sort    | $O(n)$       | $O(n^2)$     | $O(n^2)$       |
| Selection Sort | $O(n^2)$     | $O(n^2)$     | $O(n^2)$      |
| Insertion Sort | $O(n)$       | $O(n^2)$     | $O(n^2)$      |
| Merge Sort     | $O(nlogn)$ | $O(nlogn)$ | $O(nlogn)$   |
| Quick Sort     | $O(nlogn)$ | $O(n^2)$     | $O(nlogn)$   |
  
  (Information researched from https://geeksforgeeks.com for each respective sort).


#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts
  
* Bubble Sort: When the input array is sorted in reverse order, when the list’s smallest element is in the last position because the algorithm will need to make the maximum number of passes through the list 
Example: {5, 4, 3, 2, 1}

* Selection Sort: When the input array is completely unsorted, or sorted in ascending order such that you need to traverse the entire array for checking and searching (aka the minimum is always at the end of the array list). This is because selection sort has to compare each element with every single element in the unsorted portion of the array and swap them, so when it is completely reversed it needs to do more swaps. 
Example: {1, 2, 3, 4, 5}

* Insertion Sort: When the input array is in reverse order, exact opposite order needed. Insertion sort will shift all elements to the right to insert a new element so the further away it is from the target location the more elements it will need to shift. 
Example: {8, 7, 6, 5, 4}

* Merge Sort: An array that results in the worst case for merge sort is if the left and right sub arrays in the merge operation have alternate elements meaning that the every element for both array needs to be compared at least once. 
Example: {4, 0, 6, 2, 5, 1, 7, 3}  (alternating left and right subarray)

* Quick Sort: Worst case happens depending on the choice for the pivot element, most likely if the pivot is the largest or smallest element in the array because the array will then be split into a size 0 subarray and a size n-1 subarray, meaning that the algorithm will need to make n comparisons at every step of the recursion. Worst case therefore happens when the array is sorted, reverse-sorted, or consists of repeated elements. 

#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts 
* Bubble Sort: Array would be already sorted, but the sort still performs $O(n)$ comparisons.
Example: {6, 7, 8 ,9}

* Selection Sort: Array would be already sorted, but the sort still performs $O(n^2)$ comparisons. Swapping won’t occur.  Best and worst would be the same. 
Example: {1, 2, 3, 4, 5}

* Insertion Sort: Array would be already sorted, but the sort still performs $O(n)$ comparisons.
Example: {1, 2 ,3, 4, 5}

* Merge Sort: Elements in the array would be sorted in ascending order, the minimum number of of comparisons would be n. Would only be divided into individual elements then merged back. 
Example: {1, 2, 3, 4, 5, 6}

* Quick Sort: Already a sorted array or one in which all elements are equal. 
Example: {1, 2, 3, 4, 5, 6} or {1, 1, 1, 1, 1, 1}

#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 
  
  1. Merge sort: Merge sort has a worst-case memory usage of $O(n)$, where n is the size of the input array. Merge sort requires an additional temporary array of the same size as the input array to merge the subarrays.
2. Quick sort: Quick sort has a worst-case memory usage of $O(n)$, where n is the size of the input. This happens if the recursion tree is skewed, leading to increased memory use. This sort uses recursion to sort subarrays, and the recursion depth is proportional to the log of the input size.
3. Insertion sort: Insertion sort has a worst-case memory usage of $O(1)$, meaning that it does not require additional memory beyond the input array (but is slower in runtime)
4. Selection sort: Selection sort has a worst-case memory usage of $O(1)$, meaning that it does not require additional memory beyond the input array (but is slower in runtime)
5. Bubble sort: Also has a worst case memory of $O(1)$ because It sorts the array in place without requiring additional memory, but is the least efficient algorithm in terms of time complexity 
  
  source: respective https://geeksforgeeks.com pages for each sort. 

### 4. Growth of Functions
Give the following values, place them correctly into *six* categories. Use the bullets, and feel free to cut and paste the full LatexMath we used to generate them.  

$n^2$  
$n!$  
$n\log_2n$  
$5n^2+5n$  
$10000$  
$3n$    
$100$  
$2^n$  
$100n$  
$2^{(n-1)}$
#### Categories
1. Constant: 10000, 100
2. Logarithmic: $n\log_2n$
3. Linear: 3n, 100n
4. Linearithmic: $5n^2 + 5n$, $2^{(n-1)}$
5. Quadratic: $n^2$
6. Exponential: $2^n$, $n!$

### 5. Growth of Function Language

Pair the following terms with the correct function in the table. 
* Constant, Logarithmic, Linear, Quadratic, Cubic, Exponential, Factorial

| Big $O$     |  Name  |
| ------      | ------ |
| $O(n^3)$    |  cubic |
| $O(1)$      | constant  |
| $O(n)$      | linear  |
| $O(\log_2n)$ | logarithmic |
| $O(n^2)$    | quadratic  |
| $O(n!)$     | factorial  |
| $O(2^n)$    | exponential  |



### 6. Stable vs Unstable
Look up stability as it refers to sorting. In your own words, describe one sort that is stable and one sort that isn't stable  

  Stability:  A sorting algorithm’s stability is defined by how it treats equal elements in a given array. A stable algorithm would guarantee that the two identical elements appear in the same order in the sorted array that they did in the original array. An example is insertion sort, because it compares each element to one on its left and swaps them if they are in the wrong order. Because they only move one at a time two elements with the same ‘keys’ will remain in their relative order. An unstable algorithm is quick sort, because it selects a pivot element and splits the array into subarrays, so there is no guarantee that equal elements will remain in their original order.


### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 
  
  Stable algorithms are important because it can lead to unexpected results in some applications- i.e.  if there is a list of people with the same age and different names in ascending order, you want to make sure that the original order is preserved in case you want to do things like sort same-aged people with the alphabetical order of their names after you sort them by age, otherwise you’ll lose the order that you achieved when you sorted by age initially. If the algorithm is not stable, then you lose the original order of the people with the same elements (age). You cannot stack unstable sorts!

  Source: https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/


### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles. 

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.
 
  A divide and conquer algorithm: 

1. Divide the coins into equal groups (250/125)
2. Weigh the two groups on a scale against each other   
3. If one group is heavier, then that group must have the rare coin. 
4. Go back to step 1 and repeat the process on that group, dividing it into equal groups and weighing them until eventually you “reach a base case” and the rare coin is discovered
  
<br>
  
1. If both groups weigh the same: 
2. The rare coin must be in the remaining 125 coins. Divide the unweighed group into two equal groups, and one group of the remaining coins 
3. Weigh the two equal groups against each other and compare 
4. If one group is heavier, then that group must have the rare coin. 
5. Go back to step 1 and repeat the process on that group, dividing it into equal groups and weighing them until eventually you “reach a base case” and the rare coin is discovered
  
<br>
  

1. If both groups weigh the same, then the rare coin must be in the group of the remaining coin(s).
2. Weigh the remaining coin(s) against any of the other coins that are not the real coin 
3. If the remaining coins weigh more, 
4. then it is the rare coin. 
5. If it weighs the same, 
6. then the rare coin is not in this group and must be in the other group.
  
<br>

#### 7.2 Time Complexity
What is the average time complexity of your algorithm? 
  
  
This method would have a time complexity of $O(log_n)$ as the comparisons are proportional to the log of the number of coins. You divide the coins into two equal groups until you reach a group of one or two coins, which in this case would be $log_2(250) = 8$ comparisons. In process it’s quite similar to a divide and conquer algorithm like merge sort or quick sort, and has a similar time complexity. 



<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->
[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images
