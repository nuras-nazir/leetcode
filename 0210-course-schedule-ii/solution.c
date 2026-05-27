int* findOrder(int numCourses, int** prerequisites,
               int prerequisitesSize, int* prerequisitesColSize,
               int* returnSize)
{
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int* count = (int*)calloc(numCourses, sizeof(int));

    // count outgoing edges from b
    for(int i = 0; i < prerequisitesSize; i++)
    {
        int b = prerequisites[i][1];
        count[b]++;
    }

    // allocate graph
    for(int i = 0; i < numCourses; i++)
    {
        graph[i] = (int*)malloc(count[i] * sizeof(int));
        count[i] = 0;
    }

    // build graph
    for(int i = 0; i < prerequisitesSize; i++)
    {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        graph[b][count[b]++] = a;
        indegree[a]++;
    }

    // queue
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for(int i = 0; i < numCourses; i++)
    {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int* ans = (int*)malloc(numCourses * sizeof(int));
    int idx = 0;

    // topological sort
    while(front < rear)
    {
        int node = queue[front++];

        ans[idx++] = node;

        for(int i = 0; i < count[node]; i++)
        {
            int next = graph[node][i];

            indegree[next]--;

            if(indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    if(idx != numCourses)
    {
        *returnSize = 0;
        return (int*)malloc(0);
    }

    *returnSize = numCourses;

    return ans;
}
