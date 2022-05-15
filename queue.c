/**
***********************************************
* Author: Damola Awesu
* Version: 1.0
* Title: Simple Queue data structure
***********************************************
*/

#include "queue.h"


/**
* Private function
*/
static int _insert(Queue_T*q, int data){
    if(q->tail == q->queueSize-1)
        q->tail = -1;
    q->tail++;
    q->queuePtr[q->tail] = data;
    q->qcount++;
    return 0;
}

/**
**************************************************************
*
* \brief Remove the oldest data in the queue
* \param q - pointer to Queue instance
* \param top - pointer to variable to hold the removed data
* \return E_OK - successful
*
**************************************************************
*/
Std_ReturnType popQueue(Queue_T* q, int *top){
    int idx = 0;
    //printf("%d\n",q->queuePtr[0]);        //uncomment to debug issue in static alloc mode
    if(!QUEUE_EMPTY(q->qcount))
    {
        *top = q->queuePtr[0];
        while(idx < ((q->qcount)-1))
        {
            q->queuePtr[idx] = q->queuePtr[idx+1];
            idx++;
        }
        (q->qcount)--;
        (q->tail)--;
        return E_OK;
    }
    else{
        printf("Queue Empty!\n");
    }
    return E_NOT_OK;
}

/**
**************************************************************
*
* \brief Insert element at the next free spot
* \param q - pointer to Queue instance
* \param data - value to be stored in queue
* \return E_OK - successful
*
**************************************************************
*/
Std_ReturnType pushQueue(Queue_T* q,int data){
    Std_ReturnType retVal = E_OK;
    int temp;
    if(!QUEUE_FULL(q->qcount,q->queueSize))
        retVal = _insert(q,data);
    else{
        popQueue(q,&temp);
        retVal = _insert(q,data);
    }
    if(retVal != E_OK)
        return E_NOT_OK;

    return E_OK;
}

#ifdef USE_HEAP
/**
**************************************************************
*
* \brief Create instance of Queue
* \param nbElements - depth of queue
* \return Queue_T* - pointer to new Queue instance
*
**************************************************************
*/
Queue_T* createQueue(int nbElements){
    Queue_T* newQueue = malloc(sizeof(Queue_T) + (nbElements*sizeof(int)));
    if(newQueue != NULL)
    {
        newQueue->queueSize = nbElements;
        newQueue->queueInsert = pushQueue;
        newQueue->queuePop = popQueue;
        newQueue->head = 0;
        newQueue->tail = -1;
        newQueue->qcount = 0;
    }
    return newQueue;
}
#else
/**
**************************************************************
*
* \brief Create instance of Queue
* \param nbElements - depth of queue
* \return Queue_T - new Queue instance
*
**************************************************************
*/
Queue_T createQueue(){
    Queue_T newQueue;
    newQueue.queueSize = qSIZE;
    newQueue.queueInsert = pushQueue;
    newQueue.queuePop = popQueue;
    newQueue.head = 0;
    newQueue.tail = -1;
    newQueue.qcount = 0;

    return newQueue;
}
#endif
