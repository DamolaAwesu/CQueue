#include <stdio.h>
#include "queue.h"

int main(){
    Std_ReturnType retVal = E_OK;
    int buf = 0;
    
    Queue_T* q = createQueue(10);
    Queue_T* q2 = createQueue(10);
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
    for (int i = 0; i < q->qcount; i++)
    {
        printf("Val in queue = %d\n",q->queuePtr[i]);
    }
    printf("\n");
    for(int i = 0; i < q2->queueSize; i++)
    {
        retVal = q2->queueInsert(q2,i*20);
        printf("Val inserted in queue 2 = %d\n",q2->queuePtr[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        retVal = q2->queuePop(q2,&buf);
        printf("Val popped from queue 2= %d\n",buf);
    }
    printf("Current count = %d\n",q2->qcount);
    for (int i = 0; i < q2->qcount; i++)
    {
        printf("Val in queue 2 = %d\n",q2->queuePtr[i]);
    }
    
    return 0;
}


