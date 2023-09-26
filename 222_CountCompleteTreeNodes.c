typedef struct node_s node_t;
struct node_s
{
    int value;
    node_t *left;
    node_t *right;
};

int countNodes(node_t *root)
{
    if (root == NULL)
        return 0;
    return (countNodes(root->left) + countNodes(root->right) + 1);
}