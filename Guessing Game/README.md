[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9785192&assignment_repo_type=AssignmentRepo)
# Homework 02 - Guessing Game

Name: Elif Tirkes

Github Account name: skippyskiddy 

How many hours did it take you to complete this assignment (estimate)? 
- ~14 for a 2/4, ~20+ to get a 4/4. 

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- No. 


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- Yes: 
1: stackoverflow for troubleshooting 
2: geeksforgeeks.com on how a guessing game is buily logically. 


(Optional) What was your favorite part of the assignment? 
- When the game worked! Very satisfying. 

(Optional) How would you improve the assignment? 
- The test code template is VERY confusing to read (especially because we didn't have any examples to really work off of and reapply concepts from (confusing for someone who codes C at my level, at least). I am still a little confused as to how we would go about testing a program in C that requires user input through things like scanf. 

## Please responds to the following questions

1. In the *worst* case, how many guesses would our guessing game take to get the right answer if we had no hints at all?
- Under the assumption that a user DOESN'T repeat answers- 10 guesses. Starting from 5 and moving higher/lower based on hints obviously shortens this time, but the worst you can do without repeats is to run through 0 to n possible answers at least once. 
> O(N) 



2. In the *worst* case, how many guesses does it take to get the right number if we get a hint of "higher or lower" when guessing numbers 1-10 and guess intelligently (always picking in the middle of the remaining set of numbers)?
- assuming you start from the middle, in a binary-search style, around 5 guesses because the worst case will always be 1-5 guesses away from your starting point if you adhere to the hints. 
> O(log N), so the guesses would be O(log 10).  

Hint: In your answer, show this mathematically with the [log function](https://www.mathsisfun.com/algebra/logarithms.html).




If you have questions about how to how to talk about this worst case, check out Chapter 1 of [Grokking Algorithms](https://www.oreilly.com/library/view/grokking-algorithms/9781617292231/).  (see the syllabus for how to log on to O'Reilly Online for free). You only need to read the first half of the chapter to understand the reason for the maximum number of guesses; the second half of the chapter is useful, but we won't talk about big O notation and running time until next week. 

## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

