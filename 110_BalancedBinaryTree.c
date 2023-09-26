typedef struct node_s node_t;
struct node_s
{
    int val;
    node_t *left;
    node_t *right;
};

// check the heigths of the subtrees, left and right
int height(node_t *root)
{
    if (root == NULL)
        return 0;
    return 1 + fmax(height(root->left), height(root->right));
}

// remeber: check for all the subtrees, not just in general
bool isBalanced(node_t *root)
{
    // empty
    if (root == NULL)
        return true;

    int l, r;
    l = height(root->left);
    r = height(root->right);

    if (abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}