/*   Student: ELIF TIRKES
 *   Semester: SPRING 2023
 *
 * A simple queue implementation to hold int values.
 *
 */
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdlib.h> // for malloc/free
#include <stdio.h>


// The main data structure for the queue, global definition 
struct queue
{
    unsigned int back;     // The next free position in the queue
                           // (i.e. the end or tail of the line)
    unsigned int front;    // Current 'head' of the queue
                           // (i.e. the front or head of the line)
    unsigned int size;     // How many total elements we currently have enqueued.
    unsigned int capacity; // Maximum number of items the queue can hold
    int *data;             // The 'integer' data our queue holds
};
// Creates a global definition of 'queue_t' so we
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;


/** Create a queue
 * Returns a pointer to a newly created queue.
 * data should be stored on the heap (malloc). 
 * Need to malloc for queue AND the array in the queue. 
 */
queue_t *create_queue(unsigned int _capacity)
{
    queue_t* myQueue =  (queue_t*)malloc(sizeof(queue_t)); // allocate memory size of queue 
    
    if ( myQueue == NULL ) {
        return NULL; //returns NULL if malloc did not work 
    } else {
        myQueue-> back = 0; 
        myQueue-> front = 0; 
        myQueue-> size = 0; 
        myQueue-> capacity = _capacity;
        myQueue-> data = (int*)malloc(_capacity * sizeof(int)); // allocate memory for the input based on size
    }
    return myQueue;
}


/** Check if the queue is empty
 *  Returns 1 if true (The queue is completely empty, or if queue is NULL)
 * Returns 0 if false (the queue has at least one element enqueued)
 **/
int queue_empty(queue_t *q)
{
    if (q == NULL || q-> size ==0) {
        return 1; 
    } else {
        return 0;
    }
}

/** Check if the queue is Full
 *  Returns 1 if true (The queue is completely full)
 *  Returns 0 if false (the queue has more space available to enqueue items)
 **/
int queue_full(queue_t *q)
{
     if ( q-> size == q-> capacity ) {
        return 1;
    } else if (q == NULL) { //adding a defensive check here to see if q is NULL 
        return -1;
    } else {
        return 0;
    }

}

/** Enqueue a new item
 *  push a new item into our data structure
 *  Returns a -1 if the operation fails (otherwise returns 0 on success).
 **/
int queue_enqueue(queue_t *q, int item)
{
   //failure is if the queue is full or null 
    if (q == NULL || queue_full(q) == 1) {
        return -1;
    } else { 
		// add the int item to the back/tail 
		q->data[q->back] = item; 

        q->back = (q->back + 1) % q->capacity; // goes around in a circle
        // if the tail supersedes the head. uses modulo to rotate 
        // the index of the tail to the current looped index based on capacity

		// increase the current size of the queue to reflect changes to queue 
		q->size++;
		return 0;
    }
}

/** Dequeue an item
 *  Returns the item at the front of the queue and
 *  removes an item from the queue.
 *  Removing an item from the empty queue should
 *  print to stderr, and return the EXIT_FAILURE value
 *   Example:
     fputs("no items to dequeue!\n", stderr);
     return EXIT_FAILURE
 */
int queue_dequeue(queue_t *q)
{
    //failure is if the queue is full or null 
    if (q == NULL || q->size == 0) {
        fputs("no items to dequeue!\n", stderr);
        return EXIT_FAILURE;
    } else {
        int item = q->data[q->front]; // store the FIFO int in that the head is pointing at 

	    q->front = (q->front + 1) % q->capacity; //loops the head around if the size exceeds capacity
        //todo: this essentially removes the item as it is no longer pointed to 
	    
        // decrease current size by 1
	    q->size--;

	    return item; // pop the stored item
    }
}

/** Queries the current size of a queue
 *  A queue that has not been created, should return size -1, //todo: what? 
 *  and print a warning to standard error (see above)
 **/
unsigned int queue_size(queue_t *q)
{
    if (q == NULL) {
        fputs("queue has not been created", stderr);
        return q->size-1;
    } else {
        return q->size;
    }
}

/** Removes a queue and all of its elements from memory.
 *  This should be called before the program terminates.
 *  If the queue doesn't exist, simply ignore it
 **/
void free_queue(queue_t *q)
{
    if (q == NULL) {
        return;
    } else {
    // free the int array in the queue 
	free(q->data);

	// free the queue struct
	free(q);
    }
}

#endif
