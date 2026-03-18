#include <stdbool.h>
#include <stdlib.h>

bool checkValidGrid(int** grid, int gridSize, int* gridColSize) {
    
    int n = gridSize;

    // Step 1: store positions
    int (*pos)[2] = malloc(n * n * sizeof *pos);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int val = grid[i][j];
            pos[val][0] = i;
            pos[val][1] = j;
        }
    }

    // Step 2: check start
    if(pos[0][0] != 0 || pos[0][1] != 0)
        return false;

    // Step 3: validate moves
    for(int i = 0; i < n*n - 1; i++)
    {
        int r1 = pos[i][0], c1 = pos[i][1];
        int r2 = pos[i+1][0], c2 = pos[i+1][1];

        int dr = abs(r1 - r2);
        int dc = abs(c1 - c2);

        if(!((dr == 2 && dc == 1) || (dr == 1 && dc == 2)))
            return false;
    }

    return true;
}
