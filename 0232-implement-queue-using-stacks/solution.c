#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *s1;
    int *s2;
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->s1 = (int*)malloc(sizeof(int) * 100);
    obj->s2 = (int*)malloc(sizeof(int) * 100);
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

void moveStack(MyQueue* obj) {
    while(obj->top1 != -1) {
        obj->s2[++obj->top2] = obj->s1[obj->top1--];
    }
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2 == -1) {
        moveStack(obj);
    }
    return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top2 == -1) {
        moveStack(obj);
    }
    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}
