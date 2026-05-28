int findCheapestPrice(int n, int** flights, int flightsSize,
                      int* flightsColSize, int src, int dst, int k)
{
    int INF = 1000000000;

    int* dist = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // relax edges k+1 times
    for(int i = 0; i <= k; i++)
    {
        int* temp = (int*)malloc(n * sizeof(int));

        for(int j = 0; j < n; j++)
            temp[j] = dist[j];

        for(int j = 0; j < flightsSize; j++)
        {
            int u = flights[j][0];
            int v = flights[j][1];
            int cost = flights[j][2];

            if(dist[u] != INF && dist[u] + cost < temp[v])
            {
                temp[v] = dist[u] + cost;
            }
        }

        for(int j = 0; j < n; j++)
            dist[j] = temp[j];

        free(temp);
    }

    if(dist[dst] == INF)
        return -1;

    return dist[dst];
}
