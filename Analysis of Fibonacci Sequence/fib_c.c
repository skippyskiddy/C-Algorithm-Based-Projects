#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
//Coded locally on VSCODE before pushing to github for ease of troubleshooting, so VSCODE version has small changes throughout. 

#define MAX 50000

typedef uint64_t ull;

static ull table[MAX];
// Allocate space for the fib sequence 

// Dynamic programming implementaton of the fib sequence. 
// If the n input is less than 1, returns n since the first two fib numbers are equal to n. 
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

// The recursive implementation of the fibonnaci sequence. 
// If n is 0 or 1, returns n as the first two numbers are edge cases. 
// Otherwise calculates all the fibonnaci sequences to get to the n number.
// returns the result of n using the fibonnaci equation without storing it. 
// calcualtes it everytime the function is called.
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

ull* recursion_helper(int n, bool print, int version)
{
    ull* sequence = malloc(sizeof(ull) * n);
    //allocate memory for the sequence based on the size of n

    if (print) { // if you want the print the entire sequence output 
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
        printf("\n");
    } else {
        n--; // if the loop is passing over upper or lower bounds, since user input 1 means index 0 for the algorithm
        for (int i = 0; i <= n; i++) {
            ull tmp;
            if (version == 2) {
                tmp = fibdp(i);
            } else {
                tmp = fibr(i);
            }
            sequence[i] = tmp;
        }
    }
    return sequence;
}

void printSequence(ull* sequence, int size) { //prints a single sequence 
    for (int i = 0; i < size; i++) {
        printf("%lu ", sequence[i]);
    }
    printf("\n");
}

ull* getFibonacciSequence(int n, bool print, int version)
{
    if (version > 0) {
        return recursion_helper(n, print, version);
    }
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
}

void help() {
    printf("./fibonacci.out N [Type] [Print Level]\n");
    printf("\tN is the number of elements in the Fibonacci sequence, required.\n");
    printf("\t[Type] is either 2 for dynamic programming version, 1 for recursive version, 0 for iterative version, defaults to 0.\n");
    printf("\t[Print Level] is 0 for no print/speed compare only, 1 for print final sequence only, 2 for print all sequences, defaults to 0.\n");
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("at least two arguments needed, see instructions:\n");
        help();
        return 1;
    }

    const int n = atoi(argv[1]); // convert to int.
    int type = 0; //default type is iterative 
    int print = 0; //default is to not print. 
    if (argc > 2) {
        type = atoi(argv[2]);
    }
    if (argc > 3) {
        print = atoi(argv[3]);

    
    }

    bool print_it = false;
    if (print > 1) {
        print_it = true;
    }
    ull *sequence_at_n = getFibonacciSequence(n, print_it, type);
    if (print == 1) printSequence(sequence_at_n, n);
    return 0;
}
