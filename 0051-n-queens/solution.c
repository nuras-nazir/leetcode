/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free() */
 #include <stdlib.h>
#include <string.h>

int isSafe(char **board, int row, int col, int n)
{
    for(int i=0;i<row;i++)
        if(board[i][col]=='Q')
            return 0;

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        if(board[i][j]=='Q')
            return 0;

    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        if(board[i][j]=='Q')
            return 0;

    return 1;
}

void solve(int row, int n, char ***result, int *returnSize,
           int *returnColumnSizes, char **board)
{
    if(row==n)
    {
        result[*returnSize] = (char**)malloc(n*sizeof(char*));

        for(int i=0;i<n;i++)
        {
            result[*returnSize][i] = (char*)malloc((n+1)*sizeof(char));
            strcpy(result[*returnSize][i], board[i]);
        }

        returnColumnSizes[*returnSize] = n;
        (*returnSize)++;
        return;
    }

    for(int col=0; col<n; col++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col]='Q';

            solve(row+1,n,result,returnSize,returnColumnSizes,board);

            board[row][col]='.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    char ***result = malloc(1000*sizeof(char**));
    *returnColumnSizes = malloc(1000*sizeof(int));
    *returnSize = 0;

    char **board = malloc(n*sizeof(char*));

    for(int i=0;i<n;i++)
    {
        board[i] = malloc((n+1)*sizeof(char));
        for(int j=0;j<n;j++)
            board[i][j]='.';
        board[i][n]='\0';
    }

    solve(0,n,result,returnSize,*returnColumnSizes,board);

    return result;
}
