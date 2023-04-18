""" file solves for the fibonacci sequence using python. 
Coded locally on VSCODE before pushing to github for ease of troubleshooting, so VSCODE version has small changes throughout. 
Name: Elif Tirkes
Semester: Spring 2023
"""
from enum import Enum
from typing import List
from functools import lru_cache
import click
import sys

STACK_LIMIT = 1000
sys.setrecursionlimit(100000)


class FibonacciType(Enum): #specify enums for 3 approaches
    DP = 2
    RECURSIVE = 1
    ITERATIVE = 0


@lru_cache(maxsize = None) #decorater checks if function has already
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


def fib_r(n: int) -> int:
    """
    Solves the Fibonacci sequence using simple recursion.
    Does the same thing as the dp function above, without 
    the decorater calling for memoization. 
    Args:
        n (int): the nth number in the sequence

    Returns:
        the nth number in the Fibonacci sequence
    """
    if n <= 1:
        return n
    return fib_r(n - 1) + fib_r(n - 2)


def recursive_fib(n: int, print_it: bool, func=fib_r) -> List[int]:
    """
    Args:
        n: the nth number in the sequence
        print_it: bool indicating true for print, false for no print. 
        func: optional paramater for recursive or dp function 

    Returns:
        list of integers for the nth number in the Fibonacci sequence

    """
    result = [] #initialize list of integers 
    if print_it: # print wont hit stack limit as each individual number 
    #is printed rather than waiting to print out the entire sequence.
        for i in range(0, n):
            tmp = func(i)
            print(tmp, end=' ')
            result.append(tmp)
        print()
    else:
        if n > STACK_LIMIT:  # due to stack limit size, tabulate data first
       #if it is bigger, the problem is split into smaller chunks 
       #to avoid hitting the recursion limit. 
            steps = n #STACK_LIMIT
            for step in range(1, steps):
                new_n = step * STACK_LIMIT
                for i in range(0, new_n + 1): #calculates for each number in the chunk
                    func(new_n)
        for i in range(0, n):
            result.append(func(i))
    return result


def get_fibonacci_sequence(n: int, print_it: bool = False, version: FibonacciType = FibonacciType.ITERATIVE) -> List[int]:
    """
    Generates the nth number in the Fibonacci sequence based on the
    method requested.

    Args:
        n: the number in the sequence to generate
        print_it:  print out all numbers as being generated
        version:  the type/method of generation

    Returns:
        the nth number in the Fibonacci sequence
    """
    if version == FibonacciType.RECURSIVE:
        return recursive_fib(n, print_it)
    if version == FibonacciType.DP:
        return recursive_fib(n, print_it, fib_dp)
   # assumed else due to returns, Iterative version
    arr: List[int] = []
    for i in range(0, n):
        if i <= 1:
            arr.append(i) #base case 0 and 1. 
        else:
            arr.append(arr[i-1] + arr[i-2])
        if print_it:
            print(arr[-1], end=' ')
    if print_it:
        print()
    return arr[-1]

# decorators define a command line for a function that computes the fib sequence 
# with one of three algorithms 

@click.command()
@click.argument("n", type=click.IntRange(min=0, max=50000, clamp=True))
@click.option("--algo", type=click.Choice(['recursive', 'dp', 'iterative'], case_sensitive=False), default='iterative')
@click.option("--print-type", type=click.Choice(['all', 'none', 'single'], case_sensitive=False), default='none')

def main(n: int, algo: str, print_type: str):
    """
    Prints the Nth number in the Fibonacci sequence.
    Args:
        algo: string specifying the algorithm
        print_type:
        n: the nth number in the Fibonacci sequence to generate
    """
    print_it = print_type == 'all' #sets default print_type to true 
    t = FibonacciType.ITERATIVE #sets default algo to iterative 
    if algo == 'recursive':
        t = FibonacciType.RECURSIVE
    elif algo == 'dp':
        t = FibonacciType.DP
        fib_dp.cache_clear() # clear the cache for each run so results are more accurate. 
    tri = get_fibonacci_sequence(n, print_it, t)
    if print_type == 'single':
        print(tri)

  

if __name__ == "__main__":
    main()

