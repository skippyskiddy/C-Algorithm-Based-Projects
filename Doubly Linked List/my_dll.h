// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions.
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL
{
    int count;    // count keeps track of how many items are in the DLL.
    node_t *head; // head points to the first node in our DLL.
    node_t *tail; // tail points to the last node in our DLL.
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t *create_dll()
{
    // Allocate memory for the DLL structure
    dll_t *myDLL = (dll_t*)malloc(sizeof(dll_t));
    if (myDLL == NULL)
    {
        return NULL;
    }

    // Initialize head and tail fields
    myDLL->count = 0;
    myDLL->head = NULL;
    myDLL->tail = NULL;

    return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t *l)
{
    if (l == NULL)
    {
        return -1;
    }

    return (l->count == 0) ? 1 : 0; //ternary operator 
    // to check if the count is 0. if it is zero, return 1. if not, return 0.
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t *l, int item)
{
    if (l == NULL)
    {
        return -1;
    }

    // Create a new node
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) //if node is NULL
    {
        return 0;
    }

    // Initialize new node
    newNode->data = item;
    newNode->previous = NULL;

    // Update the DLL fields
    if (dll_empty(l))
    {
        // The list is empty so new node becomes the tail
        l->tail = newNode;
    }
    else
    {
        // The list is not empty
        l->head->previous = newNode; //make previous node the second node, and make new node the first node 
    }
    newNode->next = l->head; //new node becomes the first node, prev node becomes second node 
    l->head = newNode;
    l->count++; // Update list count

    return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t *l, int item) {
    // Check if NULL
    if (l == NULL) {
        return -1;
    }

    // Malloc for new node
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return 0;
    }

    // Initialize new node
    new_node->data = item;
    new_node->next = NULL;

    // Find the last node in the list
    node_t *current_node = l->head;
    if (current_node == NULL) {
        // if list is empty, make the new node the head
        // essentially the same as push front if dll is empty
        l->head = new_node;
        
    } else {
        while (current_node->next != NULL) { //traverse to the last node
            current_node = current_node->next;
        }
        // Add new node after the last node in the list
        current_node->next = new_node; //add the new node to the next of the last node 
    }

    // Update list count
    l->count++;

    return 1;
}

// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t *t) {

    // if dll NULL
    if (t == NULL) {
        return -1;
    }

    // if list is empty and there is nothing to pop
    if (t->head == NULL) {
        return 0;
    }

    // get data from first node
    int data = t->head->data; //store the removed variable to pop

    // Remove the first node
    node_t *temp = t->head;
    t->head = t->head->next; //make head the next node
    free(temp);

    // remove from list count
    t->count--; 

    return data;
}


// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t *t) {

    // Check if NULL
    if (t == NULL) {
        return -1;
    }

    // Check if empty
    if (t->head == NULL) {
        return 0;
    }

    // Find the last node and its predecessor
    node_t *last_node = t->head;
    node_t *last_node_prev = NULL;
    while (last_node->next != NULL) {
        last_node_prev = last_node; //traverse to the last node -1
        last_node = last_node->next; //traverse to the last node in the dll
    }

    // Get data from last node to pop
    int data = last_node->data;

    // Remove last node
    if (last_node_prev == NULL) {
        // if only one node, make dll null
        t->head = NULL;
    } else {
        last_node_prev->next = NULL; //make last node-1 the last node
    }
    free(last_node);

    // remove one node from count
    t->count--;

    return data; //pop the last node
}


// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t* l, int pos, int item) {
    
    //if DLL null
    if (l == NULL) {
        return -1;
    } 

    if (l->count == 0) { //implements a list if there is no element in the dll
        //create a head node if count is 0
        l->head = (node_t*)malloc(sizeof(node_t));
        l->head->data = item;
        l->head->next = l->head->previous = NULL;
        l->tail = l->head;
        l->count++;
        return 1;
    } else {
        /* Assuming the positon value will be in the range of (1,count+1)
           i.e 1 for inserting at front and (count+1) to insert at last.
        */
        pos += 1;
        if (pos == l->count+1) {  //if bigger than size
            return dll_push_back(l, item);
        }
        if (pos == 1) { //if at 1, push_front()
            return dll_push_front(l,item);
        }
        node_t* temp; //make a temp node

        if (l->count - pos >= pos - 1) { //check if new node closer to head
        //or closer to tail. If closer to head, traverse from head 
            temp = l->head; //start here
            pos = pos - 1;
            while (pos--) { //while pos != 0
                temp = temp->next;
            }
        }
        else {
            temp = l->tail; //traverse from tail 
            pos = l->count - pos;
            while (pos--) { //while pos != 0
                temp = temp->previous; //traverse backwards 
            }
        }
        //temp is used to find the node in the target location 
        // when pos == 0 from tail or head, that is the target node 

        node_t * newNode = (node_t*)malloc(sizeof(node_t));
        newNode->data = item; //initialize new node 
        newNode->next = temp; //insert new node before the temp node 
        newNode->previous = temp->previous; //place before target node 
        temp->previous->next = newNode; //replace temp with new node 
        temp->previous = newNode;
        l->count++; //plus one
        return 1;
    }
    return 0;
}



// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t *l, int pos) {
    // Check if NULL
    if (l == NULL) {
        return -1;
    }

    // Check if position is negative
    if (pos < 0) {
        return 0;
    }

    // Traverse dll to find the node at the specified position
    node_t *current_node = l->head;
    int i = 0;
    while (current_node != NULL && i < pos) {
        current_node = current_node->next;
        i++; // i will increment up to the position
    }

    // if unable to find and i is not matching pos, pos doesnt exist
    if (current_node == NULL || i != pos) {
        return 0;
    }

    // Return data in the target node
    return current_node->data;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
// Returns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the value of the node removed.
int dll_remove(dll_t *l, int pos) {
    // Check if dll is NULL
    if (l == NULL) {
        return -1;
    }

    // Check if position is negative
    if (pos < 0) {
        return 0;
    }

    // Find the node at the specified position
    node_t *current_node = l->head; //start at head
    int i = 0;
    while (current_node != NULL && i < pos) {
        current_node = current_node->next;
        i++; //increment up to pos
    }

    // Check if position exists
    if (current_node == NULL || i != pos) {
        return 0;
    }

    // Update DLL pointers for removal
    if (current_node->previous != NULL) {
        current_node->previous->next = current_node->next;
    }
    if (current_node->next != NULL) {
        current_node->next->previous = current_node->previous;
    }
    if (pos == 0) { //if at head
        l->head = current_node->next;
    }
    if (pos == l->count - 1) { //if at tail
        l->tail = current_node->previous;
    }

    // Get data from the node and free
    int data = current_node->data;
    free(current_node);
    l->count--; //remove one from count

    return data;
}

// DLL Size
// Returns -1 if the DLL is NULL.
// Queries the current size of a DLL
int dll_size(dll_t *t) {

    // Check if DLL NULL
    if (t == NULL) {
        return -1;
    }

    // Return the size of the whole list (not index! actual size, so no need to -1)
    return t->count;
}


// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the program terminates.
void free_dll(dll_t *t) {
    // Check if NULL
    if (t == NULL) {
        return;
    }

    // Free all nodes in the DLL
    node_t *current_node = t->head; //start at head
    while (current_node != NULL) { //traverse until tail
        node_t *next_node = current_node->next; //next of current 
        free(current_node); //free previous 
        current_node = next_node; 
    }

    // free the whole dll
    free(t);
}


#endif
