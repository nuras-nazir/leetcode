#define MAXN 50000
#define LOG 16

int up[MAXN][LOG];

typedef struct {
    int n;
} TreeAncestor;

TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize) {
    TreeAncestor* obj = (TreeAncestor*)malloc(sizeof(TreeAncestor));
    obj->n = n;

    for (int i = 0; i < n; i++) {
        up[i][0] = parent[i];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            if (up[i][j-1] == -1)
                up[i][j] = -1;
            else
                up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            node = up[node][j];
            if (node == -1) return -1;
        }
    }
    return node;
}

void treeAncestorFree(TreeAncestor* obj) {
    free(obj);
}
