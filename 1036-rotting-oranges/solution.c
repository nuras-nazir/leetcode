#include <stdlib.h>

typedef struct {
    int x, y;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    Node queue[10000];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: push all rotten
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            }
            else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if(fresh == 0) return 0;

    int minutes = 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // Step 2: BFS
    while(front < rear) {
        int size = rear - front;
        int infected = 0;

        for(int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for(int d = 0; d < 4; d++) {
                int nx = curr.x + dirs[d][0];
                int ny = curr.y + dirs[d][1];

                if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear++] = (Node){nx, ny};
                    fresh--;
                    infected = 1;
                }
            }
        }

        if(infected) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}
