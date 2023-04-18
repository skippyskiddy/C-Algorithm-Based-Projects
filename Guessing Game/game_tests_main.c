/*  ========== H02 - Guessing Game ============
 *
 *   Student: ELIF TIRKES
 *   Semester: SPRING 2023
 *
 *   This file builds the foundation for a 'testing' framework for the game
 *   You will want to build unit tests in this file, and run them. 
 *   You have freedom to use this file as you need. It also provides
 *   an example of how to control the random seed.
 * 
 *   For reference, we are using a file similar to this for auto-grading. 
 */

#include <stdlib.h> 
#include <string.h>

#include "guessing_game.h"  

/**
 * this test checks whether the guess_checker function runs through 1 round when the user guesses the correct
 * number on their first guess. If guess_checker returns 0 (terminates, meaning it verifies that the user 
 * guessed correctly, test_equals returns 0.
 */ 

int test_equals() {
    int userGuess = 4; //static user guess 
    int number = 4; // first random value is 4 in the random seed, made static for testing purposes. 
        if (guess_checker(userGuess, number) == 0){
            return 0; 
        }

    return 1; 
}

/**
 * this test checks whether the guess_checker function runs through 7 rounds to get to the correct value
 * when user guess increments by +1 and starts at 1, to get to the randomized value 7. It checks if the
 * function increments guessess correctly when moving upwards.
 */


int test_higher() {
    int userGuess = 1; //hypothetical starting user guess 
    int number = 7; //first value is 7
    int rounds = 1; // starts from 1 as the first round counts as 1 
    do{
        if (guess_checker(userGuess, number) == 1)
        {
            userGuess += 1; 
            rounds++; 
        }
        else if(guess_checker(userGuess, number) == 0)
        {
            return 0;
        }

    } while(rounds != 8);

    return 1;
    
    } 
/**
 * this test checks whether the guess_checker function runs through 3 rounds (total 4 rounds) to get to the
 * target number, 8, when starting from the highest guessable number. If guess_checker counts the rounds
 * correctly, the test returns 0.
 */
  
int test_lower() {
    int userGuess = 10;
    int number = 8; //third value is 8
    int rounds = 1; 
    do{
        if(guess_checker(userGuess, number) == 1){
            userGuess -= 1; 
            rounds++; 
        }
        else if(guess_checker(userGuess, number) == 0)
        {
            return 0;
        }
    } while(rounds != 4); 

    return 1; 

    }
    

/** saves the random number seed out to a file,
 * so it can be regenerated for testing purposes.
 *
 * The way to save out the values would be
 * tester.out random 20 > rand_sequence.txt
 *
 * assuming tester is what you setup for your compile command of
 *  clang -Wall tests/game_tests_main.c -o tester.out
 */
void save_random(char *count_c) {
    char *end;
    long count = strtol(count_c, &end, 10);

    for(int i = 0; i < count; i++) {
       printf("%d\n", rand() % MAX_RANDOM + MIN_RANDOM);
    }

}

/* Program entry point*/
/* Options for running 

Run the unit tests: > game_tester.out  
Run the game with a set random seed: > game_tester.out play
Generate random numbers: > game_tester.out random ## 
(where ## is a number)

*/
int main(int argc, char *argv[]) {

    /**rand() generates psuedo random numbers
     * based on a seed. In production it is common
     * to use the system clock time as the seed as that
     * is always changing. however, for tests, you want
     * to fix the random numbers so you want to set the seed.
     * 
     * The problem is that different OS version + Hardware
     * still generate different random numbers even if the
     * seed is the same. A 'hacky' (but works) way to do it
     * is write a quick program that generates a series of random
     * numbers based on a specific seed. Then call your
     * other program using that specific seed. 
     * 
     * In order to conserve files, kept this as one program using
     * the program arguments to generate the random numbers. If no
     * 
    */
    srand(1); // to force the tests to have a set random number group

    if(argc > 1) {
        if(argc > 2) {
            save_random(argv[2]);
            return 1;
        } else { // assume play
            return start_game(); /* run the game for client based testing */
        }
    }else {
        int errors = 0;
        errors += test_equals();// adds the return value from each test- if errors = 0, then all tests 
        errors += test_higher(); // ran successfully. 
        errors += test_lower();
        printf("\n**Fail %d unit tests.**\n", errors);
        return 0; 
    }
}
