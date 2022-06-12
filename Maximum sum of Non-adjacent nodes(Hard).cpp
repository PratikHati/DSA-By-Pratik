pair<int, int> getPair(Node *root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }

    pair<int, int> pl = getPair(root->left);
    pair<int, int> pr = getPair(root->right);

    pair<int, int> pcurr;

    pcurr.first = root->data + pl.second + pr.second;                   // if current add, do not add child 2nd (strict)
    pcurr.second = max(pl.first, pl.second) + max(pr.first, pr.second); //(non strict) think .......

    return pcurr;
}
int getMaxSum(Node *root)
{
    // Add your code here
    pair<int, int> p = getPair(root);

    return max(p.first, p.second);
}