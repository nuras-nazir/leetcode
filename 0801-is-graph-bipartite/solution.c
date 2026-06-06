bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int color[105];

    for(int i=0;i<graphSize;i++)
        color[i] = -1;

    int queue[105];

    for(int start=0; start<graphSize; start++)
    {
        if(color[start] != -1)
            continue;

        int front = 0;
        int rear = 0;

        queue[rear++] = start;
        color[start] = 0;

        while(front < rear)
        {
            int node = queue[front++];

            for(int i=0;i<graphColSize[node];i++)
            {
                int neigh = graph[node][i];

                if(color[neigh] == -1)
                {
                    color[neigh] = 1 - color[node];
                    queue[rear++] = neigh;
                }
                else if(color[neigh] == color[node])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
