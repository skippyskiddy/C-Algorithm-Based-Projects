# Homework 4 - Doubly Linked List

In this assignment, you will be implementing a [doubly-linked list], similar to the [linked list] lab. 

A doubly-linked list is different from the singly-linked list that we implemented in Lab 2 in that it not only maintains a 
pointer to the next node in our list but also the previous. By adding a previous field to our node, our list would looked like this:

![Double Linked List Example]

Thus a node will know who comes before and after it with the addition of a new pointer `prev`.

## Write Your Doubly Linked List

👉🏽 **Task** Using [my_dll.h], [main.c], [dll_tests.c] for templates, implement the various functions
defined in my_dll.

* my_dll.h already has the primary functions defined that we will be testing. You are free to add others. It is already defining the basic structs for your use (since we all them directly in our testing)
* main.c is for your use only. We won't look at it.
* dll_tests.c is to provide sample tests, and to provide a framework to add your own tests. Remembering: testing is validating your code works in a repeatable manner! This is important!


## Draw a picture!
Really, it helps. Here are some pictures of a few of the functions

### push_front
![Push Front on a DLL]

### push_back
![Push Back on a DLL]

### insert(int index, int data)
![Insert into a DLL]


## Unit Tests
Testing is important as it can not only find errors, but it gives you a repeatable way to validate your code (especially if you make small changes later). The tests we provided are only the start. Some things to consider:
* Fill a DLL, empty the DLL, and fill the DLL again.
* Test each function in your DLL when the DLL is not empty.
* Test each function in your DLL when the DLL is empty.

We actually ended up with around 56 different tests for your DLL in grading (though they are grouped together when reported). You will notice the reporting on failure is minimal, that is because you have to transition to using your own tests to track down errors. If you have an error in submission, ask yourself - "how can I test this to make sure it is valid in all cases". 


## 📝 Grading Rubric


Add (AG) and (MG) next to tiers, add major conditions to meet to pass each tier. 

1. Learning (AG)
   * Code compiles without errors or warnings! (use -Wall)
   * Builds a DLL
   * Checks for an empty list
   * Checks the size of the list both empty and with elements (including the size of a non-existent list / handles the error)
2. Approaching  (AG)
   * Pushing elements to a list, both sides
   * Popping elements to the list, both sides
   * Getting elements are various locations, including invalid locations
   * Makes sure functions handle empty and non-existent lists properly
3. Meets  (AG)
   * Removing elements at various points in the list
   * Inserting elements at various points in the list
   * Makes sure functions handle empty and non-existent lists properly
   * No memory leaks
4. Exceeds  (MG)
   * README.md is filled out
     * Including the questions asked
   * Have at least 3 commits (many more really)


AG - Auto-graded  
MG - Manually graded


## 📚 Resources
* [Wikipedia Doubly Linked List][doubly-linked list]
* [Visualization of Data Structures](https://visualgo.net/en/list)
* [Big O Cheat sheet](https://flexiple.com/algorithms/big-o-notation-cheat-sheet/)
* [Github Markdown Tables](https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables)
* [Markdown Latex Math](https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/writing-mathematical-expressions)




[doubly-linked list]: https://en.wikipedia.org/wiki/Doubly_linked_list
[linked list]: ../../lab-linked-list/
[dll_tests.c]: ../dll_test.c
[my_dll.h]: ../my_dll.h
[main.c]: ../main.c
[Push Front on a DLL]: dll_push_front.png
[Push Back on a DLL]: dll_push_back.png
[Insert into a DLL]: dll_insert.png
[Double Linked List Example]: dll_basic.png