#include <stdlib.h>

typedef struct {
    int price;
    int span;
} Node;

typedef struct {
    Node* stack;
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->stack = (Node*)malloc(sizeof(Node) * 10000);
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;

    while(obj->top != -1 && obj->stack[obj->top].price <= price) {
        span += obj->stack[obj->top].span;
        obj->top--;
    }

    obj->stack[++obj->top] = (Node){price, span};
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->stack);
    free(obj);
}
