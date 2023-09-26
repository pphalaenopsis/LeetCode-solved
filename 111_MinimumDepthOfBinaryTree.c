typedef struct node_s node_t;

struct node_s
{
    int value;
    node_t *left;
    node_t *right;
};

int minDepth(node_t *root)
{

    if (root == NULL)
    {
        return 0; // empty tree
    }

    // stop when you get to a leaf
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l = INT_MAX, r = INT_MAX;
    // left null, recur right
    if (root->right != NULL)
        r = minDepth(root->right);
    if (root->left != NULL)
        l = minDepth(root->left);

    return 1 + fmin(r, l);
}