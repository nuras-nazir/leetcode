struct Node* clones[101];

struct Node* dfs(struct Node* node)
{
    if(node == NULL)
        return NULL;

    if(clones[node->val] != NULL)
        return clones[node->val];

    struct Node* copy = malloc(sizeof(struct Node));

    copy->val = node->val;
    copy->numNeighbors = node->numNeighbors;

    copy->neighbors =
        malloc(sizeof(struct Node*) * node->numNeighbors);

    clones[node->val] = copy;

    for(int i = 0; i < node->numNeighbors; i++)
    {
        copy->neighbors[i] =
            dfs(node->neighbors[i]);
    }

    return copy;
}

struct Node *cloneGraph(struct Node *s)
{
    for(int i = 0; i <= 100; i++)
        clones[i] = NULL;

    return dfs(s);
}
