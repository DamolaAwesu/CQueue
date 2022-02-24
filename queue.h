#ifndef QUEUE_H_
#define QUEUE_H_

#define MAX_SIZE 10
#define QUEUE_FULL      (count==MAX_SIZE)
#define QUEUE_EMPTY     (count==0)

extern int queue[MAX_SIZE];
extern volatile int head;
extern volatile int tail;
extern volatile int count;

extern int pushQueue(int data);
extern int popQueue(int* top);

#endif // QUEUE_H_
