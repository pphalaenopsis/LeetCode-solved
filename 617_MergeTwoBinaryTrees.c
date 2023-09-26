typedef struct node_s node_t;
struct node_s
{
    int value;

    node_t *left;
    node_t *right;
};

node_t *mergeTrees(node_t *root1, node_t *root2)
{
    {
        // if both trees are empty, return empty tree
        if (root1 == NULL && root2 == NULL)
        {
            return root1;
        }
    }
    // one is empty -> return the other
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;

    // both not empty
    // use one of the trees as return tree and
    // on its left subtree add those of the left subtree of the other
    // on its right subtree add those of the right subtree of the other

    root1->value += root2->value;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}