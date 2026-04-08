#include <stdlib.h>

typedef struct Node {
    int key, val;
    struct Node *prev, *next;
} Node;

typedef struct {
    int capacity;
    Node* head;
    Node* tail;
    Node** map;
} LRUCache;

// Create node
Node* createNode(int key, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->val = val;
    node->prev = node->next = NULL;
    return node;
}

// Remove node
void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Insert at front
void insertFront(LRUCache* obj, Node* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

// Move to front
void moveToFront(LRUCache* obj, Node* node) {
    removeNode(node);
    insertFront(obj, node);
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;

    obj->map = (Node**)calloc(10001, sizeof(Node*));

    obj->head = createNode(0, 0);
    obj->tail = createNode(0, 0);

    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(obj->map[key] == NULL) return -1;

    Node* node = obj->map[key];
    moveToFront(obj, node);

    return node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->map[key] != NULL) {
        Node* node = obj->map[key];
        node->val = value;
        moveToFront(obj, node);
        return;
    }

    Node* node = createNode(key, value);
    obj->map[key] = node;
    insertFront(obj, node);

    obj->capacity--;

    if(obj->capacity < 0) {
        Node* lru = obj->tail->prev;
        removeNode(lru);
        obj->map[lru->key] = NULL;
        free(lru);
        obj->capacity++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while(curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj->map);
    free(obj);
}
