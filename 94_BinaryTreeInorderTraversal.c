/// Definition for a binary tree node.
#define N 100
typedef struct node_s node_t;
struct node_s
{
    int val;
    node_t *l;
    node_t *r;
};

void traversalR(node_t *root, int *arr, int *size)
{
    if (root == NULL)
        return;
    traversalR(root->l, arr, size);
    arr[*size] = root->val;
    *size += 1;
    traversalR(root->r, arr, size);
}

int *inorderTraversal(node_t *root, int *returnSize)
{
    int *array;
    array = (node_t *)malloc(N * sizeof(node_t));
    if (array == NULL)
    {
        fprintf(stdout, "memory allocation error!");
        exit(EXIT_FAILURE);
    }

    *returnSize = 0;
    traversalR(root, array, returnSize);
    return array;
}