
Homework 03 - Stacks and Queues -

Name: ELIF TIRKES

Github Account name: SKIPPYSKIDDY

How many hours did it take you to complete this assignment (estimate)? 6 HOURS

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- Nope. 


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- Yes- Stack Overflow, and geeksforgeeks.com to look up similar implementations/approaches to making a circular queue and linked list stack. 


(Optional) What was your favorite part of the assignment? 
- Valgrind telling me that all heap blocks are freed. I really liked how simple but complex the implementation of something like a linked list stack is. 

(Optional) How would you improve the assignment? 
- Some more resources that help/hint that we might need to work with temporary variables. Having small example code really helps. 

## Further Thinking Questions

1. Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and answer this question specifically: Why is a ring buffer useful and/or when should it be used? 
Pros: 
* You can pre-allocate memory for the ring buffer
* All operations are constant time O(1) because it doesn't require shifting elements or copying elements. 
* Especially useful when input and output to a data stram occur at different rates. 
* Because it doesn't have dynamic memory, memory leaks are also unlikely. 

The difficulty with this is that you need to know/preallocate how much memory you will need. It can be used in systems that need to remember most recent interations- i.e. messaging. One of the biggest benefits of a ring buffer is that it solves the problem of memory wastage. Additionally, you loop around the queue in a very elegant way using a modulo operator, so regardless of how many elements are added, the circular incrementation is quite efficent and elegant to implement. In conclusion, a ring buffer is best used when memory is a concern and/or memory usage is known prior to implementation, because all operations are in constant time, and traversing the queue doesn't require a constant reshuffling of memory space. 

Citations: 
P. Srivastava, “Implementing a ring buffer in Java,” Baeldung, 24-Nov-2022. [Online]. Available: https://www.baeldung.com/java-ring-buffer#:~:text=A%20ring%20buffer%20is%20an,require%20a%20shifting%20of%20elements. [Accessed: 17-Feb-2023]. 

R. A. S, “Circular queue in data structure: Overview, implementation: Simplilearn,” Simplilearn.com, 07-Feb-2023. [Online]. Available: https://www.simplilearn.com/tutorials/data-structure-tutorial/circular-queue-in-data-structure. [Accessed: 17-Feb-2023]. 


<br><br>


2. We are going to talk about stacks quite a lot in this course, so it will be important to understand them. Do a little outside research, and edit this section of the readme answering specifically: Why is a stack useful and/or when should it be used?

Stack data structures are useful when the order of operations is important. They ensure that a sysem doesn't move foreward into a new action before completing the previous action. This structure can be used for operations that involve reversing, undoing, and backtracking. A great example is programming languages, where operations in a function or recursive function sit in a stack and execute in order. One practical example is also the back button in a browser, where the pages you visit and their order of appearance determines your browser history. 

Another practical example of how useful a stack data structure can be is in the undo/redo button when using editing programs like Photoshop or Google Docs. Each change is being pushed onto a stack- you pop the most recent change off the stack when you press the undo button, and everytime you change something significant, that new change is pushed onto the stack of changes. These kind of practical implementations make stacks very useful for specific problems that require solutions that prioritize an order of operations. An unfortunate con of stacks is that random access is not possible, and that memory can be limited. 

Citations: 
A. Mathews, “The stack data structure - what is it and how is it used in JavaScript?,” Medium, 13-Feb-2020. [Online]. Available: https://levelup.gitconnected.com/the-stack-data-structure-what-is-it-and-how-is-it-used-in-javascript-23562fb8a590. [Accessed: 17-Feb-2023]. 

Admin, “Stacks and its applications for gate: Data Structures,” BYJUS, 09-Nov-2022. [Online]. Available: https://byjus.com/gate/stack-and-its-applications/#:~:text=A%20Stack%20can%20be%20used,used%20for%20systematic%20Memory%20Management. [Accessed: 17-Feb-2023]. 

S. Gautam, “Stacks in data structure,” Scaler Topics, 09-Aug-2021. [Online]. Available: https://www.scaler.com/topics/data-structures/stacks-in-data-structure/. [Accessed: 17-Feb-2023]. 



For each of these questions, we are expecting your answer to be in the range of 2-3 paragraphs (can include complexity, example usage, pros/cons, etc). Make sure to cite your sources. It is recommended you use [IEEE citation style](https://owl.purdue.edu/owl/research_and_citation/ieee_style/ieee_overview.htm) as it is most common for CS papers and research. 


## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

