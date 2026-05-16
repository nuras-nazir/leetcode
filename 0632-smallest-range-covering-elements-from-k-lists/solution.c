/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {

    int val;
    int row;
    int col;

} Node;

Node heap[4000];
int size;

void swap(Node* a, Node* b) {

    Node t = *a;
    *a = *b;
    *b = t;
}

void push(Node x) {

    heap[size] = x;

    int i = size++;

    while(i > 0) {

        int p = (i - 1) / 2;

        if(heap[p].val <= heap[i].val)
            break;

        swap(&heap[p], &heap[i]);

        i = p;
    }
}

Node pop() {

    Node ans = heap[0];

    heap[0] = heap[--size];

    int i = 0;

    while(1) {

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if(l < size && heap[l].val < heap[s].val)
            s = l;

        if(r < size && heap[r].val < heap[s].val)
            s = r;

        if(s == i)
            break;

        swap(&heap[i], &heap[s]);

        i = s;
    }

    return ans;
}

int* smallestRange(int** nums, int numsSize,
                   int* numsColSize,
                   int* returnSize) {

    size = 0;

    int maxi = -100000;

    for(int i = 0; i < numsSize; i++) {

        push((Node){nums[i][0], i, 0});

        if(nums[i][0] > maxi)
            maxi = nums[i][0];
    }

    int start = 0;
    int end = 1000000;

    while(size == numsSize) {

        Node x = pop();

        int mini = x.val;

        if(maxi - mini < end - start) {

            start = mini;
            end = maxi;
        }

        x.col++;

        if(x.col < numsColSize[x.row]) {

            x.val = nums[x.row][x.col];

            if(x.val > maxi)
                maxi = x.val;

            push(x);
        }
    }

    int* ans = malloc(2 * sizeof(int));

    ans[0] = start;
    ans[1] = end;

    *returnSize = 2;

    return ans;
}
