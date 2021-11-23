#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int pushQueue(int data);
int popQueue(void);

volatile int head = 0;
volatile int tail = -1;
volatile int count = 0;

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
    printf("Count: %d\n", count);
    for(int i = 0; i < count;i++)
        printf("Element %d: %d\n",i,queue[i]);

    return 0;
}

static int _queueFull(){
    return (count == MAX_SIZE);
}

static int _queueEmpty(){
    return (count == 0);
}

static int _insert(int data){
    if(tail == MAX_SIZE-1)
        tail = -1;
    tail++;
    queue[tail] = data;
    count++;
    return 0;
}

int popQueue(){
    if(!_queueEmpty()){
        int top = queue[head];
        head++;
        if(head == MAX_SIZE)
            head = 0;
        count--;
        return top;
    }
    else{
        printf("Queue Empty!\n");
    }
    return 0;
}

int pushQueue(int data){
    int retVal = 0;
    if(!_queueFull())
        retVal = _insert(data);
    else{
        popQueue();
        retVal = _insert(data);
    }
    if(retVal != 0)
        return -1;
    else
        printf("Data added to Queue; Slots left = %d\n", MAX_SIZE-count);
    return 0;
}
