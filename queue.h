/**
****************************************************************
* File: queue.h
* description: Header file containing queue struct definitions
* @author: Damola Awesu
* @version: 1.0
* @title: Simple Queue data structure
****************************************************************
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "queueConfig.h"

#if defined (MAX_SIZE)
#define qSIZE   MAX_SIZE
#endif

#define QUEUE_FULL(c,x)       (c==x)
#define QUEUE_EMPTY(c)         (c==0)

typedef enum {
    E_OK=0,
    E_NOT_OK
}Std_ReturnType;

//Forward declaration of Queue type
typedef struct queue_t Queue_T;

//Function pointer definitions
typedef Std_ReturnType (*qInsert)(Queue_T*, int);
typedef Std_ReturnType (*qPop) (Queue_T*, int*);

/**
**********************************
* \brief Queue struct definition
*
**********************************
*/
struct queue_t{
    int queueSize;                                      /**< number of elements in the queue        */
    int head;
    int tail;
    int qcount;
    qInsert queueInsert;                                /**< function pointer to insert function    */
    qPop queuePop;                                      /**< function pointer to delete function    */
    #ifdef USE_HEAP
    int queuePtr[];                                     /**< dynamically allocated array            */
    #else
    int queuePtr[qSIZE];                                      /**< pointer to statically allocated array  */
    #endif
};

/**
**********************************
* Function prototypes
**********************************
*/
#ifdef USE_HEAP
extern Queue_T* createQueue(int nbElements);            /**< Queue object constructor                       */
#else
extern Queue_T createQueue(void);             /**< Queue object constructor                       */
#endif
extern Std_ReturnType pushQueue(Queue_T*,int data);     /**< Function to insert data at end of queue        */
extern Std_ReturnType popQueue(Queue_T*,int* top);      /**< Function to delete the data at start of queue  */

#endif // QUEUE_H_
