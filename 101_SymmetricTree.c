typedef struct node_s node_t;
struct node_s
{
    int val;
    node_t *left;
    node_t *right;
};

bool symmetric(node_t *p, node_t *q)
{
    // if both emtry == true
    if (p == NULL && q == NULL)
    {
        return true;
    }

    // check p->left == q->right and viceversa
    if (p != NULL && q != NULL && p->val == q->val)
        return (symmetric(p->left, q->right) && symmetric(p->right, q->left));

    return false;
}

bool isSymmetric(struct TreeNode *root)
{
    // divide into two trees
    return symmetric(root->left, root->right);
}