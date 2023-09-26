typedef struct node_s node_t;
struct node_s
{
    int value;

    node_t *left;
    node_t *right;
};

bool identicalTrees(node_t *root1, node_t *root2)
{
    // both NULL == true
    if (root1 == NULL && root2 == NULL)
        return true;

    // one or the other NULL == false
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    // check data on current node and recur
    // returns true if all following return true
    // 1. current node value equal
    // 2. equal left subtree
    // 3. equal right subtree
    return (root1->value == root2->value && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right));
}

bool isSubtree(node_t *root, node_t *subRoot)
{
    // first tree NULL -> false, cannot have subtree
    if (root == NULL)
        return false;

    // second tree NULL -> true, always a subtree
    if (subRoot == NULL)
        return true;

    // check current root
    if (identicalTrees(root, subRoot))
        return true;

    // current node not compatible, call on next node
    // either true on right or on left subtree or both -> ||

    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}