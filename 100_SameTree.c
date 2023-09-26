typedef struct node_s node_t;
struct node_s
{
    int val;
    node_t *left;
    node_t *right;
};

bool isSameTree(node_t *p, node_t *q)
{

    // empty trees
    if (p == NULL && q == NULL)
        return true;

    // if not empty
    if (p != NULL && q != NULL)
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));

    // one empty, the other not, or just not the same
    return false;
}