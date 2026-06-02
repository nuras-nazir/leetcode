int findTheCity(int n, int** edges, int edgesSize,
                int* edgesColSize, int distanceThreshold)
{
    int dist[101][101];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=1000000000;
        }
    }

    for(int i=0;i<edgesSize;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        dist[u][v]=w;
        dist[v][u]=w;
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] =
                    dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int answer=-1;
    int minCount=1000000;

    for(int i=0;i<n;i++)
    {
        int count=0;

        for(int j=0;j<n;j++)
        {
            if(i!=j &&
               dist[i][j] <= distanceThreshold)
            {
                count++;
            }
        }

        if(count <= minCount)
        {
            minCount=count;
            answer=i;
        }
    }

    return answer;
}
