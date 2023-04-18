# Midterm p1: Report on Analysis of Fibonacci Series
* **Author**: Elif Tirkes
* **GitHub**: [Link](https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy.git)
* **Semester** Spring 2023
* **Languages Used**: C, Python

## Overview
This report explores the time complexity and speed differences between various algorithmic implementations of the Fibonacci sequence, specifically through recursive, iterative, and dynamic programming based algorithms implemented in C and Python3. 

The Fibonacci sequence is a series of numbers in which each number is the sum of the two previous numbers, except for the first two numbers in the sequence, 0 and 1. Below is the mathematical equation for calculating a Fibonacci sequence [^1]: 

$$F_{n}=F_{n-1}+F_{n-2}$$

Where $F_n$ is the $nth$ number in the Fibonacci sequence, $F_{n-1}$ is the $(n-1)th$ number, and $F_{n-2}$ is the $(n-2)th$ number.

A typical sequence with n = 20 would look like this: 

``` text
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181
```
We start with the first two terms, 0 and 1 and skip them as exceptions. We can then add the previous two terms together, making the third term 0+1=1. To get the fourth term, we add the second and third terms, so 1+1=2 and so forth. By continuing this pattern we’re generating a Fibonnaci sequence by adding the two previous terms to get the following term in the sequence.

### Iterative Algorithm
There are multiple ways to solve the Fibonacci sequence. One of the most frequently used methods are iterative algorithms, where a loop begins after the first two terms 0 and 1, and calculates the next term as a sum of the two previous terms, repeating until the desired term in the sequence is calculated. An iterative solution to this problem has a time complexity of  $O(n)$, as the algorithm performs a consistent and constant amount of work at each term in the sequence, regardless of the size of the number. The growth of time is linear to the size of the sequence.  Below is an isolated snippet from the C code used to calculate the iterative algorithm in this report. The time complexity of $O(n)$ is illustrated in how the algorithm iterates from 2 to n and calculates the i’th Fibonacci number, displaying linear growth in time complexity.

```c 
   // implied else for iterative version
    ull* sequence = malloc(sizeof(ull) * n);
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) //starts from 2 to handle 0 and 1 as a base case.
    {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
    if (print) printSequence(sequence, n);

    return sequence;
```

### Recursive Algorithm
Alternatively, the Fibonacci sequence can be solved recursively. This is when a function calls itself with the previous terms in its sequence calculation until the base case (n <= 1 in this case ) of the first two terms is reached. The recursive function will have a time complexity of $O(2^n)$ because the algorithm will call itself twice at each step, creating an exponential increase in the time it takes to calculate n at each iteration. For example, when calculating the 100th term of the sequence using a recursive algorithm, the 99th and 98th term will also need to be calculated, which also requires the 97th and 96th terms to be calculated and so forth, until the base case is reached for each term. This makes recursive algorithms quite inefficient in terms of time and space complexity for larger values of N. Below is an isolated snippet from the C code used to calculate the recursive algorithm in this report, the time complexity is shown in the way in which the function calls itself twice for each input in `return fibr(n-1) + fibr(n-2);` until it reaches the base case, creating an exponential number of function calls. 

```c 
// The recursive implementation of the fibonacci sequence. 
// If n is 0 or 1, returns n as the first two numbers are edge cases. 
// Otherwise calculates all the fibonacci sequences to get to the n number.
// returns the result of n using the fibonacci equation without storing it. 
// calculates it everytime the function is called.
ull fibr(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibr(n-1) + fibr(n-2);
    }
}
```

### Dynamic Programming Algorithm
Recursive algorithms can be equipped with memoization, which means that results of each computation are stored in a table so that the same computation doesn’t need to be calculated more than once. This is a dynamic programming principle, which is the third algorithm that is used to explore the Fibonacci sequence in this report. With dynamic programming, the time complexity of a recursive algorithm for the Fibonacci sequence problem can be reduced back down to $O(n)$, making it as efficient as the iterative algorithm as it stores previous values in a table and retrieves them when needed. Below is an isolated snippet from the C code used to calculate the dynamic programming algorithm in this report. As seen in the first `else if` condition, the code checks and retrieves the stored value in a table to avoid duplicate calculations, making time complexity of $O(n)$ since each Fibonnaci number is calculated at most once. 

```c 
// Dynamic programming implementation of the fib sequence. 
// If the n input is less than 1, return n since the first two fib numbers are equal to n. 
// If the n input is already stored in the table array (memoized) then it calls it from the table array. 
// If the nth number is not in the table, it recursively calls itself with the n-1 and n-2 input
// and stores the result in the table array for future use. 
ull fibdp(int n)
{
    if (n <= 1) {
        return n;
    } else if (table[n] > 0) {
        return table[n];
    } else {
        table[n] = fibdp(n-1) + fibdp(n-2);
        return table[n];
    }
}
```

The following table summarizes the typical time and space complexities of the three algorithms. There are various different ways to implement these algorithms and solutions across various languages, which will improve or complicate the time and space complexity of each algorithm for the Fibonacci sequence[^2]. For the sake of this report we’ll be exploring a more simplistic, common approach using C and Python:


| Algorithm           | Big O    | Space Complexity |
|---------------------|----------|------------------|
| Iterative           | $O(n)$   | $O(1)$           |
| Recursive           | $O(2^n)$ | $O(n)$           |
| Dynamic Programming | $O(n)$   | $O(n)$           |


The space complexity for the iterative algorithm is $O(1)$ (a constant). As the nth value changes the space and memory used remains the same because the algorithm only stores the previous two terms in the sequence at any calculation. After the calculation for the nth value is done, the previous two terms are replaced with the following two necessary terms to calculate n+1, making the amount of memory constant regardless of the size of the input. For the recursive and dynamic programming implementation, space complexity stays at $O(n)$ since the entire sequence is usually stored in an array, and in the memoized implementation, there are at most n recursive calls on a call stack for the recursive implementation [^3]. The latter two algorithms store all the previous values required to get to the nth value, which means that memory size grows linearly with the size of the input [^4].

The section below further details the iterative, recursive, and dynamic programming approaches to solving n iterations of the Fibonacci sequence using C and Python.



## Empirical Data & Discussion 

The six algorithms were run through several iterations of varying sizes and set to time out at 60 seconds, to ensure algorithms with a higher time complexity (i.e. recursive) time out and allow algorithms with lower time complexity (dynamic programming) to continue to produce results. The algorithm ran 6000 iterations for the sake of our analysis, and ran up to 500,000 iterations with each 500 steps printed to see if the faster algorithms would time out at larger inputs. The results are presented in a table below, showing the final iteration and last timed incident for each algorithm below.


### Findings 

| Algorithm             | N (timeout < 60 seconds) | Last Timed Incident (Seconds) |
|-----------------------|--------------------------|-------------------------------|
| Iterative C           |                 449,501+ |                       0.00477 |
| Recursive C           |                       48 |                      41.15231 |
| Dynamic Programming C |                 449,501+ |                       0.01987 |
| Iterative P           |                 449,501+ |                       0.13193 |
| Recursive P           |                       41 |                       49.6663 |
| Dynamic Programming P |                     1000 |                       0.04771 |

As expected and predicted in the time complexity in the overview, the recursive algorithm for both languages timed out first, with the recursive C function timing out at n = 48, and the recursive Python function timing out at n = 41. The slight difference in the timeout of these functions has to do with the attributes and limitations of each language, and is explored in the language analysis section. Below is a visual comparison of the timeout for the C and Python recursive functions.

<p align="center">
<img src="https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/recursive_c.png?raw=true" width=60% height=60%>

<img src="https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/recursive_py.png?raw=true" width=60% height=60%>
</p>


As predicted, the fastest algorithm was dynamic programming with C a run time of 0.01987 seconds at n = 449,501. The second fastest was the iterative algorithm with C at 0.00477 seconds and n = 449,501, and the third fastest was dynamic programming with Python (which timed out earlier than Python’s iterative algorithm, due to stack size and memory usage). Although the iterative implementation in Python was slower than the top three, it notably did not time out whereas the dynamic programming implementation timed out at a relatively lower iteration, illustrating a clear time-memory-reliability tradeoff when solving larger problems. 

### Dynamic and Iterative Algorithms for Larger Problems 

Below is a comparison of an iterative and dynamic programming implementation for C and Python at n = 6000. Recursive algorithms were omitted from this comparison because they timed out in earlier iterations. 

<p align="center">
<img src="https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/C_itvsdy.png?raw=true" width=60% height=60%>
   
   

<img src="https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/Python_itvsdy.png?raw=true" width=60% height=60%>

</p>


C’s implementation of the dynamic programming algorithm and the iterative algorithm remained within an interval of ~0.0020 - 0.0024 seconds, but had a significant number of outliers throughout the full run, with upward spikes going up to 0.0037 seconds for the dynamic programming algorithm and 0.0032 for the iterative algorithm. While this might seem like a minuscule time difference, when implementing these algorithms in practice and for even larger numbers, spikes in performance like this can degrade performance and combine into a significant slowdown for total runtime. Small differences like this can be detrimental in practical systems like real-time systems (autonomous vehicles, airplanes) and high-volume systems like financial trading, where even a couple of spikes in performance could have significant real life consequences, so it is important to note here that in comparison to Python, C was proportionally less stable when dealing with a large problem, even though it had a faster output for each iteration. 

On the other hand, there are fewer such spikes in Python’s implementation of a dynamic programming algorithm and iterative algorithm, and the time for each iteration varies between 0.04 and 0.048 seconds.  It’s important to note that the dynamic programming algorithm timed out at n = 1000, so this isn’t a true comparison of Python’s capabilities with larger problems.

While Python was slower than C when implementing these two algorithms, it was less likely to have proportionally large outliers as the size of the problem grew. However, the difference between the upper and lower bounds, although consistent, is greater than that of C. Illustrated below is a look at the statistical dispersion of the values at n = 6000 using the Interquartile Range (IQR) to better understand variability across the 3 algorithms in both languages. 

Using IQR and the upper and lower boundaries, outlier detection is illustrated in the table below. The final row in the table shows the comparable variability for each algorithm by dividing the number of iterations with the number of outliers in the run. Python has more variability across three algorithms, even though C has more one-off cases that are proportionally higher than the average runtime. 

The graphs above illustrate C’s infrequent, but proportionally higher outliers, while the IQR table illustrates that Python has higher variability (a higher number of outliers) across all three algorithms overall. 

Further supporting the first observation on C’s unexpected and disproportionate spikes in performance are outliers that had to be manually removed from this data. One example is n = 3397 for the iterative algorithm in C which took 0.03167 seconds compared to an average runtime of 0.002 seconds, and n = 48 and n = 2811 for the dynamic programming algorithm which took 0.00459 and 0.0048 seconds respectively compared to an 0.00220 second average. In comparison, Python had one disproportionate outlier at n = 1002 for the iterative algorithm, which had a 0.14 second runtime compared to an average of 0.04 seconds. 

<p align="center">
<img src="https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/IQR_analysis.png?raw=true" width=80% height=80%>
</p>


Large outliers likely occurred due to background tasks on the computer in which the programs were running. Memory and CPU being allocated for various unrelated tasks likely created an artificial delay in the outputs, but the difference between C and Python’s variability is interesting especially because the program computed results for both languages around the same time. Possible reasons for this are further explored in the Language Analysis section. 

<p align="center">
<img src="https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/500k_comparison.png?raw=true" width=60% height=60%>
</p>

A large input comparison is shown above to compare trends for the three algorithms that did not time out for smaller input sizes. C shows proportionally higher outliers for the dynamic programming algorithm, after a big jump in runtime at around n = 51,501. Python’s time increases incrementally, with a significant spike in performance at n = 18,001 and n = 46,001. 

Interestingly, the dynamic programming implementation in C has the shortest runtime and best performance for the first 50,000 iterations, where it is then slower than the iterative algorithm in C. This is most likely because the way in which the ‘subproblems’ in the dynamic programming algorithm are stored gradually become inefficient for larger problems- for this case, it’s likely because the array becomes too large to traverse efficiently. In order for dynamic programming to be utilized to its maximum potential discussed in the overview section, it needs to be optimized- implementing things like parallelization, removing unnecessary calculations and better memory management is important when trying to fully leverage the time-saving benefits of dynamic programming. For the sake of this analysis, practical implementations are not explored, but for a more complex implementation of dynamic programming, these elements must absolutely be considered. 

The data suggests that C is significantly faster than Python, and dynamic programming is the fastest out of the three algorithms given that memory management and data traversion are optimized for the simple Fibonacci sequence problem. In the dynamic programming implementation above, the dynamic programming algorithm for Python times out too early, and this is likely because of uncovered stack limitation and memory management issues. Assuming it performs similarly in terms of execution time for a larger input size, Python's dynamic programming can likely supersede the speed of C's iterative algorithm implmentation.



## Language Analysis
The code mentioned in this analysis can be found in the following files:
* [fib_c.c](https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/fib_c.c)  -- implementation of Fibonacci sequence in C.
* [fib_python.py](https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/fib_python.py) -- implementation of Fibonacci sequence in Python.
* [test_runner_edited.py](https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-skippyskiddy/blob/main/test_runner_edited.py ) -- run script to help with tests and keep timings


Because C is a lower level language with increased flexibility for optimization, which is great for testing the performance of various algorithms. I wanted to pick Python as my second language as it’s a very popular program primarily because it's an interpreted language with a high memory overhead, which makes it more simple to use than other languages. This means  it’s easier for users to code in Python, as the language does a majority of the ‘interpreting’ and essential background work (like memory allocation) without being told to do so. However, the cost of interpretability is slower execution time. Python is meant to be generally great for many applications, and can be tweaked to be optimized as much as possible, whereas C is meant to be built and optimized in a more ‘ground up’ fashion for specific problems.  In other words, for an optimization and execution analysis like this one, C and Python seem like two “polarities” that would provide a lot of information on the pros and cons of different languages to analyze algorithmic problems. 


### Language 1: C

The iterative version of the algorithm in C below is quite straightforward but can easily consume a lot of memory if the input size gets increasingly larger. However, this is a concern shared across all three algorithms. The iterative implementation is quite simple, adhering to the implementation of the mathematic formula. 
```c
   // implied else for iterative version
    ull* sequence = malloc(sizeof(ull) * n);
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) //starts from 2 to handle 0 and 1 as a base case.
    {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
    if (print) printSequence(sequence, n);

    return sequence;
```

The code for the recursive implementation in C was quite simplistic and similar to the python implementation.  The function holds a base case and calls itself until it reaches the base case.

```c
ull fibr(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibr(n-1) + fibr(n-2);
    }
}
```

The dynamic programming implementation in C built on the recursive version, adding only a second condition to check if the current sequence was already calculated. If it was, then the value was called from a table and not recalculated, speeding up the time complexity to $O(n)$ as discussed in the overview section. 

```c
ull fibdp(int n)
{
    if (n <= 1) {
        return n;
    } else if (table[n] > 0) {
        return table[n];
    } else {
        table[n] = fibdp(n-1) + fibdp(n-2);
        return table[n];
    }
```
Memory was allocated within a helper function called `recursion_helper` illustrated below. An array the size of the input n is allocated in the beginning of the program call. This function also assists in printing and selecting the correct algorithm based on input, and storing new variables for n if the specific Fibonacci sequence hasn’t been computed yet. 

```c
       for (int i = 0; i < n; i++)
        {
            ull tmp;
            if (version == 2) {
                tmp = fibdp(i);  // stores the dp sequence in the tmp variable 
            } else if (version == 1) {
                tmp = fibr(i); // stores the recursive sequence in the tmp variable 
            }
            if (i+1 == n) sequence[i] = tmp; // if the current iteration is the last one, stores the last computed number to print 
            printf("%lu ", tmp);
        }
```

Overall, the biggest concern while using C is always making sure that memory management is correct and scales appropriately as the program grows. My memory allocation errors are limited in this code, and should be improved, especially for even larger inputs. The code here also has a fixed-size array to store the Fibonacci sequence, which can lead to a gradual buffer overflow if n is too large. 


### Language 2: Python
For Python, I was curious to see how much of a cost simplicity, flexibility, and interpretation would bring to a problem in which execution speed is important, and also see how Python’s dynamic typing and automatic memory management would influence performance of the three Fibonacci sequence algorithms. 


One key advantage of Python is its built-in support for large integers, which allowed me to easily calculate the Fibonacci sequence without worrying about integer overflows. It also had a myriad of libraries to explore and optimize for specific solutions, but I opted to compare a more simplistic implementation of the three algorithms to make it more comparable to the C implementation, which is a comparatively less library-intensive language. My choice here left a lot of room for optimization for my Python implementations, as Python typically has great performance for general use but benefits from tweaking and optimization for a specific purpose, and my empirical analysis supported this as Python’s performance was significantly less compared to C. Even though Python will always be more computationally expensive to run than C due to it being a higher level language, there are ways to better allocate memory and utilize libraries to increase processing time.


```python
def fib_r(n: int) -> int:
    """
    Solves the Fibonacci sequence using simple recursion.
    Does the same thing as the dp function above, without 
    the decorator calling for memoization. 
    Args:
        n (int): the nth number in the sequence

    Returns:
        the nth number in the Fibonacci sequence
    """
    if n <= 1:
        return n
    return fib_r(n - 1) + fib_r(n - 2)
```

When it came to the implementation, I built the recursive function first and added the `@lru_cache` decorator to the recursive function to create a dynamic programming implementation of the Fibonacci sequence. This is a simple function - it sets a base case and recursively calls itself until the base case is reached. For memory management in my dynamic programming algorithm, I relied on the `@lru_cache` decorator from the `functools` module to memoize repeated parts of the sequence. This method is quite easy to use and gives the user the ability to control the size of the cache to prevent it from getting too large. I added a `fib_dp.cache_clear()` condition to the program entry to clear the cache for each iteration and return more accurate results. 



```python
@lru_cache(maxsize = None) #decorator checks if function has already
# been called with the same number (n)and is memoized.
def fib_dp(n: int) -> int:
    """
    Solves for Fibonacci sequence using dynamic programming & memoization. 
    Args:
        n: the nth number in the sequence

    Returns:
        the nth number in the Fibonacci sequence
    """
    if n <= 1:
        return n #0 & 1 are base cases.
    return fib_dp(n - 1) + fib_dp(n - 2)
```

For function calls and program arguments, I kept the `click` library and enums to make selection easier.  Overall,  the Python implementation was kept simplistic- I did not use a lot of libraries or modules and ‘mirrored’ the simplicity of the C implementation of algorithms as much as possible.

Python's dynamic typing can also lead to increased memory usage and slower performance when compared to statically-typed languages like C. To address these concerns, it’s better to optimize code and make use of Python's built-in data structures to reduce memory usage. Additionally, the recursion limit and stack limit in Python was difficult to work through as memory allocation isn’t as flexible as it is in C. 



### Comparison and Discussion Between Experiences
C provides direct access to memory, making it a good choice for implementing low-level algorithms that require fine-grained control over memory usage. This also means that C requires careful memory management, and errors in memory allocation and deallocation can lead to serious issues.

Python, on the other hand, is a high-level interpreted language that provides automatic memory management, making it easier to write and maintain code. However, Python's dynamic typing and garbage collection leads to slower performance and increased memory usage when compared to C. For a relatively simple problem like calculating the Fibonacci sequence, there aren’t too many difficult-to-manage complex relationships within the program, so performance wasn’t drastically different and illustrative of what might happen in a practical scenario where execution time between these two languages is critical. 

However, the difference in performance is clear. C is faster than Python in all scenarios, and the algorithms performed as expected based on their Big O analysis. Dynamic programming was the fastest, followed by the iterative algorithm, and finally recursive algorithm. The language comparison here is truly interesting, as the implementations of all three algorithms are almost identical omit the memory management difference between the programs, yet C still executes the slowest algorithm (recursive) faster than Python. This comes to show how important it is to optimize programs to their specific problem using various tools like memory management, data structures, and possibility parallelization (which was not explored here as it is beyond the scope of this paper, and because the goal in this comparison was to keep all implementations simple and comparable across the two languages). 

This comparison also illustrates the importance of language use- a high level language like Python, without significant and effortful optimization, will likely not perform as well for a lot of problems that are time-sensitive. What C can do with a few adjustments to memory management may be much more difficult to implement in Python due to the number of higher level nature of the language. Likewise, C will always require more effort to successfully implement as it is not an interpreting language like Python, and requires manual memory management- creating more potential room for error, and making it difficult to work with more complex programs. 

Overall, C is great for simple optimization as in the case with the Fibonacci sequence. However, because it is a lower level language, the implementation for this sequence has less room for improvement. In a future report, it’d be interesting to compare C’s fast execution time with a Python program that is optimized for a problem like this and uses different methods to manage memory and stack limits, and which utilizes libraries as much as possible. Memory and stack limits in Python were one of the most significant slowing factors in my experiment. 


## Conclusions / Reflection
I can confidently say that this assignment gave me a newfound appreciation for code optimization and the different qualities of programming languages. I had a general grasp of why it’s important to optimize code, but as I tinkered and worked through my implementation and ran several test iterations, I realized how much of a difference an optimized, concise implementation can make when compared to one that is more redundant. 

I theoretically understood why higher and lower level languages have different applications and why there is no ‘universal programming language’ but I now have a much better appreciation for programming language differences. Python is higher level language that is much easier to implement, so coding up the Fibonacci sequence was quite smooth and simple - however, having previously worked with C, I was left unsatisfied. Several questions ran through my mind: how much memory was being used? Was the automatic memory allocation doing large inputs justice? Why was my dynamic programming algorithm crashing before it hit the timeout interval? I could tell there were bounds within my Python code, but they were harder to uncover because the program is higher level and intended to ‘hide’ these details unless the programmer intentionally tweaks them. In C, because the language is lower level and things have to be done from the ground-up (like memory management) it was easier to both troubleshoot issues and edit my program in an effort to optimize the speed of the program. 

In addition to the above, experiencing Big O notation first-hand was also really insightful. Writing up code and seeing it adhere to the predicted Big O time complexity was satisfying and informative, and I have better insight on why and how there is variability between different algorithms. It was also insightful to notice discrepancies (like outliers) in my empirical analyses and try to understand what’s happening in my code, hardware, or script that might be impacting the outcome of my results. 

Overall, even though calculating the Fibonnaci sequence is a straightforward task and doesn’t fully reflect the complexity of these takeaways in real-life practical applications, I feel much more equipped to discuss and apply different approaches to problems (as I did here with the three algorithms), and break larger problems into subproblems and optimize them to get to a desired, improved solution. In future iterations I’d like to be more confident tweaking code and exploring more complicated additions to my code- I left a lot of things to optimize with my Python implementation for the sake of keeping it simple and understandable, but utilizing the complexity of higher-level languages and building on optimizations is something I’d like to explore. 


## References
[^1]:“Fibonacci number,” Wikipedia, 06-Mar-2023. [Online]. Available: https://en.wikipedia.org/wiki/Fibonacci_number. [Accessed: 06-Mar-2023].
[^2]:“Program for fibonacci numbers,” GeeksforGeeks, 17-Feb-2023. [Online]. Available: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/. [Accessed: 06-Mar-2023].
[^3]:committedandroidercommittedandroider 8, “What is the space complexity of a recursive Fibonacci algorithm?,” Stack Overflow, 01-Jan-1962. [Online]. Available: https://stackoverflow.com/questions/28756045/what-is-the-space-complexity-of-a-recursive-fibonacci-algorithm. [Accessed: 06-Mar-2023].
[^4]:S. T. Ahmed, “Fibonacci iterative vs. Recursive,” Medium, 21-Feb-2021. [Online]. Available: https://syedtousifahmed.medium.com/fibonacci-iterative-vs-recursive-5182d7783055#:~:text=Space%20Complexity%3A,O(1)%20or%20constant. [Accessed: 06-Mar-2023]. 


