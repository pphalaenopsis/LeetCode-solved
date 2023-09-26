typedef struct node_s node_t;
struct node_s
{
    int value;

    node_t *left;
    node_t *right;
};

int traversal(node_t *root, int *tilt)
{
    if (root == NULL)
    {
        return 0;
    }

    int l, r;
    l = traversal(root->left, tilt);
    r = traversal(root->right, tilt);

    *tilt += abs(l - r);
    return (l + r + root->value);
}

int findTilt(node_t *root)
{
    // traverse the tree (post-order)
    // while traversing sum the current node tilt
    // to the previous level node tilt

    int tilt = 0;
    traversal(root, &tilt);
    return tilt;
}