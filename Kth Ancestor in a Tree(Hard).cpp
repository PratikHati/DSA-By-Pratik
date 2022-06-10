
int kthancestor(Node *root, int &k, int node)
{
    // Code here
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node)
    {
        return node;
    }
    int x = k;
    int y = k;

    int l = kthancestor(root->left, x, node);

    int r = kthancestor(root->right, y, node);

    if (x == INT_MAX)
    {
        k = INT_MAX;
        return l;
    }

    if (y == INT_MAX)
    {
        k = INT_MAX;
        return r;
    }

    if (l != -1 && r == -1)
    {
        x--;
        if (x == 0)
        {
            k = INT_MAX; // VERY IMPRTANT (CHECKMATE) Think....................
            return root->data;
        }
        k = x;
        return node;
    }

    if (l == -1 && r != -1)
    {
        y--;
        if (y == 0)
        {
            k = INT_MAX; // VERY IMPRTANT (CHECKMATE) Think....................
            return root->data;
        }
        k = y;
        return node;
    }

    return -1;
}