/* Student: ELIF TIRKES
 *   Semester: SPRING 2023
 *
 * A simple queue unit-tst implementation 
 *
 */

// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall queue_test.c -o queue_test
//
// Run with: ./queue_test
//

#include "myqueue.h"

#include <stdio.h> // For IO operations


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.

// Tests that a new queue was created and the capacity
// was properly set.
int unitTest1(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(30);
    if (30 == testq->capacity)
    {
        passed = 1;
    }
    free_queue(testq);

    return passed;
}

// Tests adding multiple items to a queue
int unitTest2(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(10);
    queue_enqueue(testq, 1);
    queue_enqueue(testq, 2);
    queue_enqueue(testq, 3);
    queue_enqueue(testq, 4);
    queue_enqueue(testq, 5);
    queue_enqueue(testq, 6);
    queue_enqueue(testq, 7);
    queue_enqueue(testq, 8);
    queue_enqueue(testq, 9);
    queue_enqueue(testq, 10);
    if (10 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing
int unitTest3(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing multiple times
int unitTest4(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

int unitTest5(int status) // check if the queue full passes
{
    int passed = 0;

    queue_t *testq = create_queue(1);
    queue_enqueue(testq, 1);
    if (1 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        free_queue(testq);
        return 0;
    }

    queue_dequeue(testq);
    if (0 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_queue(testq);

    return passed;
}


// see if queue correctly returns empty
int unitTest6(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(0);

    if (1 == queue_empty(testq))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    
    free_queue(testq);

    return passed;
}

// confirm if queue does not add anything to empty queue 
int unitTest7(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(0);
    queue_enqueue(testq, 5);
    queue_enqueue(testq, 10);

    if (testq->size == 0)
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    
    free_queue(testq);

    return passed;
}

// Dequeuing from  empty queue
int unitTest8(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(1);
    int result = queue_dequeue(testq);

    if (result == 0 && queue_size(testq) == 0)
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Enqueuing when queue is full
int unitTest9(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(1);
    queue_enqueue(testq, 1);
    int result = queue_enqueue(testq, 2); //should return -1 

    if (result == -1 && queue_size(testq) == 1)
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}


int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    NULL};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;

    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter+1);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}
