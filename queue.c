#include <stdio.h>
#include "queue.h"

#define QUEUE_FULL      (count==MAX_SIZE)
#define QUEUE_EMPTY     (count==0)

int queue[MAX_SIZE];

volatile int head = 0;
volatile int tail = -1;
volatile int count = 0;

static int _insert(int data){
    if(tail == MAX_SIZE-1)
        tail = -1;
    tail++;
    queue[tail] = data;
    count++;
    return 0;
}

int popQueue(int *top){
    int idx = head;
    if(!QUEUE_EMPTY)
    {
        *top = queue[head];
        while(idx < (count-1))
        {
            queue[idx] = queue[idx+1];
            idx++;
        }
        count--;
        tail--;
        return 0;
    }
    else{
        printf("Queue Empty!\n");
    }
    return -1;
}

int pushQueue(int data){
    int retVal = 0; int temp;
    if(!QUEUE_FULL)
        retVal = _insert(data);
    else{
        popQueue(&temp);
        retVal = _insert(data);
    }
    if(retVal != 0)
        return -1;

    return 0;
}
