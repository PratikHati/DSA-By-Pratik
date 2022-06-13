Node *Solve(int in[], int post[], int start, int end, int &curr, int n)
{

    if (curr < 0 || start > end)
    {
        return NULL;
    }
    int rootdata = post[curr--];

    // find it's index in in[]
    int rootindex = -1;
    for (int i = start; i <= end; i++)
    {

        if (in[i] == rootdata)
        {
            rootindex = i;
            break;
        }
    }

    Node *root = new Node(rootdata);
    root->right = Solve(in, post, rootindex + 1, end, curr, n);
    root->left = Solve(in, post, start, rootindex - 1, curr, n);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int curr = n - 1;
    return Solve(in, post, 0, n - 1, curr, n);
}