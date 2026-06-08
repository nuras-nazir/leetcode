#define MOD 1000000007LL
#define INF 1000000000000000000LL

int countPaths(int n, int** roads, int roadsSize, int* roadsColSize)
{
    long long dist[205];
    long long ways[205];

    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        ways[i]=0;
    }

    int adj[205][205];
    int wt[205][205];
    int deg[205]={0};

    for(int i=0;i<roadsSize;i++)
    {
        int u=roads[i][0];
        int v=roads[i][1];
        int w=roads[i][2];

        adj[u][deg[u]]=v;
        wt[u][deg[u]++]=w;

        adj[v][deg[v]]=u;
        wt[v][deg[v]++]=w;
    }

    dist[0]=0;
    ways[0]=1;

    int vis[205]={0};

    for(int cnt=0;cnt<n;cnt++)
    {
        int u=-1;

        for(int i=0;i<n;i++)
        {
            if(!vis[i] &&
               (u==-1 || dist[i]<dist[u]))
                u=i;
        }

        vis[u]=1;

        for(int i=0;i<deg[u];i++)
        {
            int v=adj[u][i];
            long long w=wt[u][i];

            if(dist[u]+w < dist[v])
            {
                dist[v]=dist[u]+w;
                ways[v]=ways[u];
            }
            else if(dist[u]+w == dist[v])
            {
                ways[v]=(ways[v]+ways[u])%MOD;
            }
        }
    }

    return ways[n-1];
}
