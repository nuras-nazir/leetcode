typedef struct {
    int** adj;
    int* size;
    int* visited;
} Graph;

bool dfs(Graph* g, int course)
{
    // cycle found
    if(g->visited[course] == 1)
        return false;

    // already checked
    if(g->visited[course] == 2)
        return true;

    // mark visiting
    g->visited[course] = 1;

    for(int i = 0; i < g->size[course]; i++)
    {
        int next = g->adj[course][i];

        if(!dfs(g, next))
            return false;
    }

    // mark completed
    g->visited[course] = 2;

    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    Graph g;

    g.adj = (int**)malloc(numCourses * sizeof(int*));
    g.size = (int*)calloc(numCourses, sizeof(int));
    g.visited = (int*)calloc(numCourses, sizeof(int));

    // count edges
    for(int i = 0; i < prerequisitesSize; i++)
    {
        int a = prerequisites[i][0];
        g.size[a]++;
    }

    // allocate memory
    for(int i = 0; i < numCourses; i++)
    {
        g.adj[i] = (int*)malloc(g.size[i] * sizeof(int));
        g.size[i] = 0;
    }

    // build graph
    for(int i = 0; i < prerequisitesSize; i++)
    {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        g.adj[a][g.size[a]++] = b;
    }

    // check every course
    for(int i = 0; i < numCourses; i++)
    {
        if(!dfs(&g, i))
            return false;
    }

    return true;
}
