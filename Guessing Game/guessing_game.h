/*
 *   Student: ELIF TIRKES
 *   Semester: SPRING 2023
 *
 * A simple guessing game program.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H

#define MAX_RANDOM 10
#define MIN_RANDOM 1

/** add as many functions as you need
 * remember good design practices
 */

/** Start location for the guessing game - this must
 * remain the starting point. DO NOT reset the random seed.
 */

int ROUNDS = 5; //constant variable declaring rounds 
int roundCounter[5]; // initializing the size of the array based on the number of rounds   
int guess(); //declaring the three main functions before they are used 
int guess_checker();
int print_results();

/**
 * starts the game by calling the guess() function in a for loop that runs for as many rounds as specified in
 * the global constant vairbale above. After the loop terminates, this function also calls printresults() 
 * which prints the results of the guessing game that was storied in the array roundCounter[] 
 */ 
 

int start_game()
{
    printf("Welcome to the guessing game. Let's get started.\n");
   
    for (int i = 0; i < ROUNDS; i++)
    {
        roundCounter[i] = guess(); // add return roundcounter value to array
    }
    print_results(); //prints results at the end of the game based on the values in the global array  
    return 0;
}

/** this function initialized the number of guesses to 1 since the game initiates with the first guess.
 *  It generates a number between the declared min and max in the variable number, and sets user guess 
 *  to 0 to initialize it so it can be replaced by user input in scanf. 
 *  the function then uses a do while loop and prompts the user guess until the user guess is equal to the
 *  randomly generated number. After every guess and iteration of the loop, the function calls guess_checker()
 */ 


int guess()
{
    int numberOfGuesses = 1;
    int number = rand() % MAX_RANDOM + MIN_RANDOM;
    int userGuess = 0; // placeholder variable for userGuess input

    do{
        printf("Guess a number between 1 and %d\n", MAX_RANDOM);
        scanf("%d", &userGuess);  // get user input
        numberOfGuesses += guess_checker(userGuess, number);
       }
    while(userGuess != number); 
       
    return numberOfGuesses; // returns total guesses for each round to append into the roundCounter array 
}
/**
 * guess_checker is called by guess() to check if the user guess is higher or lower than the selected
 * number. It takes user guess and selected number as parameters. 
 * After every failed guess, guess_checker() returns 1 to guess() to add to the number of guesses
 * each round took. If the user guess matches the number, guess_checker returns 0 and the do while loop
 * in guess() terminates.
 */  

int guess_checker(int userGuess, int number){

        if (userGuess > number)
        {
            printf("Your guess is too high.\n");
            return 1;
        }
        else if (userGuess < number)
        {
            printf("Your guess is too low.\n");
            return 1; 
        }
        else
        {
            printf("Congratulations! You found it.\n");
            return 0; 
        }
}
/** print_results is called after the total number of rounds for each game is complete. It uses the values in the roundCounter array to return the score for each guessing round.
 */ 

int print_results()
{
    for (int i = 1; i <=  ROUNDS; i++) //count starts at 1 since the first guess is 1 round 
    {
        printf("Round %d took you %d guesses.\n", i, roundCounter[i - 1]);
    }
    return 0;
}
#endif


