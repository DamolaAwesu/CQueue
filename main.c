#include <stdio.h>
#include "queue.h"

int main(){
    Std_ReturnType retVal = E_OK;
    int buf = 0;
    #ifdef USE_HEAP
    Queue_T* q = createQueue(10);
    Queue_T* q2 = createQueue(5);
    for(int i = 0; i < q->queueSize; i++)
    {
        retVal = q->queueInsert(q,i*20);
        printf("Val in queue = %d\n",q->queuePtr[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        retVal = q->queuePop(q,&buf);
        printf("Val popped = %d\n",buf);
    }
    printf("Current count = %d\n",q->qcount);
    #else
    Queue_T q = createQueue(10);
    Queue_T q2 = createQueue(5);
    for(int i = 0; i < q.queueSize; i++)
    {
        retVal = q.queueInsert(&q,i*20);
        printf("Val in queue = %d\n",q.queuePtr[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        retVal = q.queuePop(&q,&buf);
        printf("Val popped = %d\n",buf);
    }
    printf("Current count = %d\n",q.qcount);

    #endif
    return 0;
}


