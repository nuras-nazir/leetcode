int find(int parent[], int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

bool Union(int parent[], int a, int b)
{
    int pa = find(parent, a);
    int pb = find(parent, b);

    // already connected -> cycle
    if(pa == pb)
        return false;

    parent[pa] = pb;

    return true;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));

    // initialize
    for(int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    int* ans = (int*)malloc(2 * sizeof(int));

    for(int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // if cycle found
        if(!Union(parent, u, v))
        {
            ans[0] = u;
            ans[1] = v;
        }
    }

    *returnSize = 2;

    return ans;
}
