int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {

    bool visited[1000] = {false};
    int minDist[1000];

    for(int i = 0; i < pointsSize; i++)
        minDist[i] = INT_MAX;

    minDist[0] = 0;

    int cost = 0;

    for(int i = 0; i < pointsSize; i++)
    {
        int u = -1;

        for(int j = 0; j < pointsSize; j++)
        {
            if(!visited[j] &&
               (u == -1 || minDist[j] < minDist[u]))
            {
                u = j;
            }
        }

        visited[u] = true;
        cost += minDist[u];

        for(int v = 0; v < pointsSize; v++)
        {
            if(!visited[v])
            {
                int dist =
                    abs(points[u][0] - points[v][0]) +
                    abs(points[u][1] - points[v][1]);

                if(dist < minDist[v])
                    minDist[v] = dist;
            }
        }
    }

    return cost;
}
