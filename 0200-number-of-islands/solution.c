void dfs(char** grid, int rows, int cols, int r, int c)
{
    if(r < 0 || r >= rows ||
       c < 0 || c >= cols ||
       grid[r][c] == '0')
        return;

    grid[r][c] = '0';

    dfs(grid, rows, cols, r+1, c);
    dfs(grid, rows, cols, r-1, c);
    dfs(grid, rows, cols, r, c+1);
    dfs(grid, rows, cols, r, c-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];

    int count = 0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j] == '1')
            {
                count++;

                dfs(grid, rows, cols, i, j);
            }
        }
    }

    return count;
}
