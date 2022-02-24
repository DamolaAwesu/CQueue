#include <stdio.h>
#include "queue.h"

long fibonacci(int n);
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
    //fibonacci(30);
    printf("Tail = %d\n",tail);
    printf("Head = %d\n",head);

    return 0;
}

long fibonacci(int n)
{
    int prev_result[] = {0,1};
    int result = 0;int i = 2;
    printf("%d " ,prev_result[0]);
    printf("%d " ,prev_result[1]);
    if (n < 2)
        printf("%d\n " ,prev_result[0]+prev_result[1]);
    else
    {
        while (i < n)
        {
            result = prev_result[0]+prev_result[1];
            printf("%d ",result);
            prev_result[0] = prev_result[1];
            prev_result[1] = result;
            i++;
        }
    }
    return 0;
}
