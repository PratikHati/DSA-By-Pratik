#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Node

{

public:
    int data = 0;

    vector<Node *> children;

    Node(int data)

    {

        this->data = data;
    }
};

Node *constructor01(vector<int> &arr)

{

    if (arr.size() == 0)

        return NULL;

    vector<Node *> stack;

    stack.push_back(new Node(arr[0]));

    Node *root = stack[0];

    for (int i = 1; i < arr.size(); i++)
    {

        if (arr[i] != -1)

        {

            Node *node = stack.back();

            Node *nnode = new Node(arr[i]);

            node->children.push_back(nnode);

            stack.push_back(nnode);
        }

        else

            stack.pop_back();
    }

    return root;
}
int depth(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int child_count = node->children.size();
    int ans = 0;
    for (int i = 0; i < child_count; i++)
    {
        ans = max(ans, depth(node->children[i]));
    }

    return ans + 1;
}
void levelOderZigZag(Node *node)

{

    // write code here
    int d = depth(node);
    vector<vector<int>> ans(d);

    queue<pair<Node *, int>> q;

    q.push(make_pair(node, 1));

    int curr_level = 1;

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        if (p.second != curr_level)
        {
            curr_level = p.second;
        }

        ans[curr_level - 1].push_back(p.first->data);
        q.pop();

        // insert all of its child
        int number_child = p.first->children.size();

        for (int i = 0; i < number_child; i++)
        {
            q.push(make_pair(p.first->children[i], p.second + 1));
        }
    }

    for (int i = 0; i < d; i++)
    {
        if (i % 2 != 0)
        {

            reverse(ans[i].begin(), ans[i].end());
        }
    }

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = constructor01(arr);
    levelOderZigZag(root);
}

int main()
{
    solve();
    return 0;
}