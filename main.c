#include <stdio.h>
#include "queue.h"

extern volatile int count;

int main(){
    pushQueue(5);
    pushQueue(10);
    pushQueue(87);
    pushQueue(14);
    pushQueue(7);
    pushQueue(8);
    pushQueue(54);
    pushQueue(100);
    pushQueue(85);
    pushQueue(55);
    pushQueue(30);
    pushQueue(96);
    popQueue();
    pushQueue(30);
    popQueue();
    pushQueue(96);
    printf("Count: %d\n", count);
    for(int i = 0; i < count;i++)
        printf("Element %d: %d\n",i,queue[i]);
    printf("Tail = %d\n",tail);
    printf("Head = %d\n",head);

    return 0;
}
