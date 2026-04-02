#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->arr = (int*)malloc(sizeof(int) * 100); // max size
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->arr[obj->rear++] = x;
    obj->size++;

    // rotate
    for(int i = 0; i < obj->size - 1; i++) {
        obj->arr[obj->rear++] = obj->arr[obj->front++];
    }
}

int myStackPop(MyStack* obj) {
    if(obj->size == 0) return -1;
    obj->size--;
    return obj->arr[obj->front++];
}

int myStackTop(MyStack* obj) {
    return obj->arr[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->arr);
    free(obj);
}
