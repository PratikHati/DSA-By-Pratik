
class Solution
{
public:
    Node *Solve(int in[], int pre[], int start, int end, int &curr, int n)
    {

        if (curr >= n)
        {
            return NULL;
        }

        if (start > end)
        {
            return NULL;
        }

        int rootdata = pre[curr++]; // monor mistake

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

        root->left = Solve(in, pre, start, rootindex - 1, curr, n);
        root->right = Solve(in, pre, rootindex + 1, end, curr, n);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        int currindex = 0;
        return Solve(in, pre, 0, n - 1, currindex, n);
    }