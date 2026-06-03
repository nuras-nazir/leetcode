int** updateMatrix(int** mat, int matSize, int* matColSize,
                   int* returnSize, int** returnColumnSizes)
{
    int rows = matSize;
    int cols = matColSize[0];

    *returnSize = rows;

    *returnColumnSizes = malloc(rows * sizeof(int));

    for(int i=0;i<rows;i++)
        (*returnColumnSizes)[i] = cols;

    int **dist = malloc(rows * sizeof(int*));

    for(int i=0;i<rows;i++)
        dist[i] = malloc(cols * sizeof(int));

    int q[100000][2];
    int front=0,rear=0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(mat[i][j]==0)
            {
                dist[i][j]=0;

                q[rear][0]=i;
                q[rear][1]=j;
                rear++;
            }
            else
            {
                dist[i][j]=-1;
            }
        }
    }

    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    while(front<rear)
    {
        int r=q[front][0];
        int c=q[front][1];
        front++;

        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr>=0 && nr<rows &&
               nc>=0 && nc<cols &&
               dist[nr][nc]==-1)
            {
                dist[nr][nc]=dist[r][c]+1;

                q[rear][0]=nr;
                q[rear][1]=nc;
                rear++;
            }
        }
    }

    return dist;
}
