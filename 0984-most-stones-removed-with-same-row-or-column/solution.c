void dfs(int node, int n, int** stones, int* vis)
{
    vis[node] = 1;

    for(int i=0;i<n;i++)
    {
        if(!vis[i] &&
          (stones[i][0] == stones[node][0] ||
           stones[i][1] == stones[node][1]))
        {
            dfs(i,n,stones,vis);
        }
    }
}

int removeStones(int** stones, int stonesSize, int* stonesColSize)
{
    int vis[1000]={0};
    int components = 0;

    for(int i=0;i<stonesSize;i++)
    {
        if(!vis[i])
        {
            components++;

            dfs(i, stonesSize, stones, vis);
        }
    }

    return stonesSize - components;
}
