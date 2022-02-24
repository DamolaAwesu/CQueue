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

int popQueue(){
    int idx = head;
    if(!QUEUE_EMPTY)
    {
        int top = queue[head];
        while(idx < (count-1))
        {
            queue[idx] = queue[idx+1];
            idx++;
        }
        count--;
        tail--;
        return top;
    }
    else{
        printf("Queue Empty!\n");
    }
    return 0;
}

int pushQueue(int data){
    int retVal = 0;
    if(!QUEUE_FULL)
        retVal = _insert(data);
    else{
        popQueue();
        retVal = _insert(data);
    }
    if(retVal != 0)
        return -1;

    return 0;
}
