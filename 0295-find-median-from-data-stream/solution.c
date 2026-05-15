typedef struct {

    int maxHeap[50005];
    int minHeap[50005];

    int maxSize;
    int minSize;

} MedianFinder;


void maxHeapInsert(int* heap, int* size, int val) {

    int i = (*size)++;

    heap[i] = val;

    while(i > 0) {

        int p = (i - 1) / 2;

        if(heap[p] >= heap[i])
            break;

        int t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;

        i = p;
    }
}

void minHeapInsert(int* heap, int* size, int val) {

    int i = (*size)++;

    heap[i] = val;

    while(i > 0) {

        int p = (i - 1) / 2;

        if(heap[p] <= heap[i])
            break;

        int t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;

        i = p;
    }
}

int maxHeapPop(int* heap, int* size) {

    int ans = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while(1) {

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if(l < *size && heap[l] > heap[largest])
            largest = l;

        if(r < *size && heap[r] > heap[largest])
            largest = r;

        if(largest == i)
            break;

        int t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;

        i = largest;
    }

    return ans;
}

int minHeapPop(int* heap, int* size) {

    int ans = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while(1) {

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if(l < *size && heap[l] < heap[smallest])
            smallest = l;

        if(r < *size && heap[r] < heap[smallest])
            smallest = r;

        if(smallest == i)
            break;

        int t = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = t;

        i = smallest;
    }

    return ans;
}


MedianFinder* medianFinderCreate() {

    MedianFinder* obj =
        (MedianFinder*)malloc(sizeof(MedianFinder));

    obj->maxSize = 0;
    obj->minSize = 0;

    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    if(obj->maxSize == 0 || num <= obj->maxHeap[0]) {

        maxHeapInsert(obj->maxHeap, &obj->maxSize, num);
    }
    else {

        minHeapInsert(obj->minHeap, &obj->minSize, num);
    }

    if(obj->maxSize > obj->minSize + 1) {

        int x = maxHeapPop(obj->maxHeap, &obj->maxSize);

        minHeapInsert(obj->minHeap, &obj->minSize, x);
    }

    else if(obj->minSize > obj->maxSize) {

        int x = minHeapPop(obj->minHeap, &obj->minSize);

        maxHeapInsert(obj->maxHeap, &obj->maxSize, x);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->maxSize > obj->minSize) {

        return obj->maxHeap[0];
    }

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {

    free(obj);
}
