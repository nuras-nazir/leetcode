#include <stdbool.h>

bool dfs(char** board, int rows, int cols, int r, int c, char* word, int index) {
    // if all characters matched
    if (word[index] == '\0')
        return true;

    // boundary checks
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;

    // current cell mismatch
    if (board[r][c] != word[index])
        return false;

    // mark cell as visited
    char temp = board[r][c];
    board[r][c] = '#';

    // explore 4 directions
    bool found =
        dfs(board, rows, cols, r + 1, c, word, index + 1) ||
        dfs(board, rows, cols, r - 1, c, word, index + 1) ||
        dfs(board, rows, cols, r, c + 1, word, index + 1) ||
        dfs(board, rows, cols, r, c - 1, word, index + 1);

    // backtrack (restore cell)
    board[r][c] = temp;

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (dfs(board, rows, cols, r, c, word, 0))
                return true;
        }
    }
    return false;
}

