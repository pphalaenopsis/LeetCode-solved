typedef struct node_s node_t;
struct node_s
{
    int val;

    node_t *left;
    node_t *right;
};

int maxx(int a, int b)
{
    return a > b ? a : b;
}

int height(node_t *root)
{
    if (root == NULL)
        return 0;
    int l, r;
    l = height(root->left);
    r = height(root->right);
    return (maxx(l, r) + 1);
}

// longest path between two nodes in a tree
// either passing through the root or not
int diameterOfBinaryTree(node_t *root)
{
    if (root == NULL)
        return 0;

    /*
     * if we pass through the root: get the heights of left
     * and right subtrees, sum
     */

    int left, right;
    left = height(root->left);
    right = height(root->right);
    int byRoot;
    byRoot = left + right; // consider root

    // not passing through root -> dismeter of subtrees
    int hleft, hright;
    hleft = diameterOfBinaryTree(root->left);
    hright = diameterOfBinaryTree(root->right);
    int noRoot = maxx(hleft, hright);

    return (maxx(byRoot, noRoot));
}