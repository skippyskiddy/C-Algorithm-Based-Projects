/* Student: ELIF TIRKES
 *   Semester: SPRING 2023
 *
 * A simple queue unit-tst implementation
 *
 */

#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.

// Tests the capacity of a stack
int unitTest1(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    if (MAX_DEPTH == test_s->capacity)
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Enqueu several items into a stack and test the size
int unitTest2(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    stack_enqueue(test_s, 3);
    stack_enqueue(test_s, 4);
    stack_enqueue(test_s, 5);
    stack_enqueue(test_s, 6);
    stack_enqueue(test_s, 7);
    stack_enqueue(test_s, 8);
    stack_enqueue(test_s, 9);
    stack_enqueue(test_s, 10);

    if (10 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack
int unitTest3(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }

    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack multiple times
int unitTest4(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Simple enqueu and deque stack test
// Also confirms that a stack is full
int unitTest5(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(1);
    stack_enqueue(test_s, 1);
    if (1 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        return 0;
    }

    stack_dequeue(test_s);
    if (0 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_stack(test_s);

    return passed;
}

//test if the stack count moves up correctly 
int unitTest6(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(10);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 6);
    stack_enqueue(test_s, 2);
    stack_enqueue(test_s, 21);
    stack_enqueue(test_s, 5);
    stack_enqueue(test_s, 19); //count == 7 

    if (test_s->count == 7)
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        return 0;
    }

    stack_dequeue(test_s);
    stack_dequeue(test_s);
    stack_dequeue(test_s);
    stack_dequeue(test_s);
    stack_dequeue(test_s); 
    stack_dequeue(test_s);
    stack_dequeue(test_s); // count == 0

    if (test_s->count == 0)
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        return 0;
    }

    free_stack(test_s);

    return passed;
}


// create_stack should return a non-NULL pointer
int unitTest7(int status)
{
int passed = 0;
stack_t *test_s = create_stack(MAX_DEPTH);
if (test_s != NULL)
{
    passed = 1;
}

free_stack(test_s);

return passed;
}

// Test that stack_empty returns 1 for a newly created stack
int unitTest8(int status)
{
int passed = 0;
stack_t *test_s = create_stack(MAX_DEPTH);
if (stack_empty(test_s) == 1)
{
    passed = 1;
}
free_stack(test_s);

return passed;
}

// Test that stack_enqueue returns 0 when successful
int unitTest9(int status)
{
int passed = 0;
stack_t *test_s = create_stack(MAX_DEPTH);
int result = stack_enqueue(test_s, 42);
if (result == 0)
{
    passed = 1;
}

free_stack(test_s);

return passed;
}

// Test that free_stack properly frees memory
int unitTest10(int status)
{
int passed = 0;
stack_t *test_s = create_stack(MAX_DEPTH);
stack_enqueue(test_s, 1);
stack_enqueue(test_s, 2);
free_stack(test_s);

// Attempt to access freed test_s stack
int *data = (int *)test->head;
if (data == NULL)
{
    passed = 1;
}
return passed;
}

// TODO: Add more tests here
// add your own, and uncomment the provided tests as
// things are implemented
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
unitTest10,
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
