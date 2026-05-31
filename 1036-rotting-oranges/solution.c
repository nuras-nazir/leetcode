typedef struct
{
    int r;
    int c;
} Queue;

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];

    Queue q[10000];
    int front = 0;
    int rear = 0;

    int fresh = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 2)
            {
                q[rear++] = (Queue){i,j};
            }
            else if(grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    if(fresh == 0)
        return 0;

    int minutes = 0;

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(front < rear)
    {
        int size = rear - front;
        int changed = 0;

        for(int i = 0; i < size; i++)
        {
            Queue curr = q[front++];

            for(int d = 0; d < 4; d++)
            {
                int nr = curr.r + dr[d];
                int nc = curr.c + dc[d];

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    fresh--;

                    q[rear++] = (Queue){nr,nc};
                    changed = 1;
                }
            }
        }

        if(changed)
            minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}
