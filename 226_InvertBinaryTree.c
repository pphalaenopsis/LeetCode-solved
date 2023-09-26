typedef struct node_s node_t;
struct node_s
{
    int value;

    node_t *left;
    node_t *right;
};

node_t *invertTree(node_t *root)
{
    // swap the function of the right and left pointers per each node
    node_t *tmp;

    if (root == NULL)
        return NULL;

    invertTree(root->left);
    invertTree(root->right);

    tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}