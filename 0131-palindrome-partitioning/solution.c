#include <stdlib.h>
#include <string.h>

int isPalindrome(char *s, int l, int r)
{
    while(l < r)
    {
        if(s[l] != s[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}

void dfs(char *s, int start, int len,
         char ****result,
         int *returnSize,
         int **returnColumnSizes,
         char **path,
         int pathSize,
         int *capacity)
{
    if(start == len)
    {
        if(*returnSize >= *capacity)
        {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char**));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }

        (*result)[*returnSize] = malloc(pathSize * sizeof(char*));
        (*returnColumnSizes)[*returnSize] = pathSize;

        for(int i=0;i<pathSize;i++)
        {
            (*result)[*returnSize][i] = strdup(path[i]);
        }

        (*returnSize)++;
        return;
    }

    for(int end=start; end<len; end++)
    {
        if(isPalindrome(s,start,end))
        {
            int size = end-start+1;

            char *sub = malloc(size+1);
            strncpy(sub, s+start, size);
            sub[size] = '\0';

            path[pathSize] = sub;

            dfs(s,end+1,len,result,returnSize,returnColumnSizes,path,pathSize+1,capacity);

            free(sub);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes)
{
    int len = strlen(s);

    int capacity = 100;

    char ***result = malloc(capacity * sizeof(char**));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    char *path[20];

    *returnSize = 0;

    dfs(s,0,len,&result,returnSize,returnColumnSizes,path,0,&capacity);

    return result;
}
