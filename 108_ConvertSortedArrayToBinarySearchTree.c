// Definition for a binary tree node
#define N 100
typedef struct node_s node_t;
struct node_s
{
    int val;
    node_t *left;
    node_t *right;
};

node_t *nodeAlloc()
{
    node_t *node;
    node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL)
    {
        fprintf(stderr, "memory allocation error!");
        exit(EXIT_FAILURE);
    }
    return node;
}

node_t *new_node(int data)
{
    node_t *new;
    new = nodeAlloc();

    new->val = data;
    new->left = new->right = NULL;
    return new;
}

node_t *sortedBST(int num[], int start, int end)
{
    // end case, end of array
    if (start > end)
        return NULL;

    // middle element
    int middle = (end + start) / 2;
    node_t *new = new_node(num[middle]);

    // exclude the middle element, already processed
    new->left = sortedBST(num, start, middle - 1);
    new->right = sortedBST(num, middle + 1, end);

    return new;
}

node_t *sortedArrayToBST(int *nums, int numsSize)
{
    return sortedBST(nums, 0, numsSize - 1);
}