# Homework 04: Doubly Linked List

Name: Elif Tirkes

Github Account name: SKIPPYSKIDDY

How many hours did it take you to complete this assignment (estimate)? ~6 (not super accurate because I started a long time ago)

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- No


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- https://www.programiz.com/dsa/doubly-linked-list 
- https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/
- & various stackoverflow pages


(Optional) What was your favorite part of the assignment? 
- Nice to focus on just doubly linked lists. I enjoyed it 

(Optional) How would you improve the assignment? 
-N/A


## Understanding Time Complexity

1. Using a markdown table and markdown/latex math, show the BigO for Arrays, Singly Linked Lists, Doubly Linked Lists (so total of 3). For the columns, you will look at the Worst Case Time Complexity for Access, Search/Find,	Insertion, and Deletion. 

| Data Structure      | Access Time Complexity | Search/Find Time Complexity | Insertion Time Complexity                    | Deletion Time Complexity                     |
|---------------------|------------------------|-----------------------------|----------------------------------------------|----------------------------------------------|
| Arrays              | $O(1)$                   | $O(n)$                     | $O(n)$                                         | $O(n)$                                         |
| Singly Linked Lists | $O(n)$                   |$O(n)$                        | $O(1)$ (at head), $O(n)$ (anywhere else)         | $O(1)$ (at head), $O(n)$ (anywhere else)         |
| Doubly Linked Lists | $O(n)$                   | $O(n)$                        | $O(1)$ (at head or tail), $O(n)$ (anywhere else) | $O(1)$ (at head or tail), $O(n)$ (anywhere else) |

(source: stackoverflow verification for individual columns, and geeksforgeeks.com)

<br>

2. Usually for singly and doubly linked lists, we reference both the head and tail for speed considerations. What would be the cost if you only had your head referenced, and you wanted to push to the tail of either? 

Normally would take $O(n)$ time complexity for singly linked lists because you need to traverse the list from head to tail to insert the new element, you have to traverse the whole list to find the last element to add a new one after it. For a doubly linked list the time complexity is $O(1)$ to update the tail pointer because doubly linked lists have a reference to both the head and the tail. Singly linked lists do not have a reference to the tail so the whole list must be traversed. 

However, if the doubly linked list has no tail reference, it would also take $O(n)$ time to push the tail. 


<br>

3. Name an example where an array is better than a linked list, and an example where a linked list is better than an array. Make sure to reference the big O as part of your reasoning. 

Arrays are better in scenarios where you need to frequently access random elements, in which case they have $O(1)$ time complexity because you can just access the element directly with the index i.e. `arr[n]`. Linked lists have an $O(n)$ time complexity for random access, an element at a specific index needs to be traversed to from the head or the tail of the list. 

When it comes to frequently deleting and adding items to a list, a linked list is much better with an $O(1)$ time complexity- you can just traverse to the desired position of the target node and rereference the head and tail pointers accordingly to efficiently insert an element or delete an element at any given position. An array would need to shift values left/right, giving it a time complexity of $O(n)$.

<br>

Note: Make sure look at your finished markdown in the browser hosted on github or via a markdown preview extension. To confirm the notation is showing up properly. 

## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

