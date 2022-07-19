#include <iostream>
#include <climits>
#include <string.h>
#include <vector>

using namespace std;

// structure of node
class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair
{
public:
    Node *node = nullptr;
    int state = 0;

    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int size(Node *node)
{
    // write your code here
    int count = 0;
    if (node == NULL)
    {
        return count;
    }

    int l = 0;
    int r = 0;
    if (node->left != NULL)
    {
        l = size(node->left);
    }

    if (node->right != NULL)
    {
        r = size(node->right);
    }

    return l + r + 1;
}

int height(Node *node)
{
    // write your code here
    int h = -1;

    if (node == NULL)
    {
        return h;
    }

    int l = 0;
    int r = 0;

    l = height(node->left);

    r = height(node->right);

    return max(l, r) + 1;
}

int maximum(Node *node)
{
    // write your code here
    int m = INT_MIN;

    if (node == NULL)
    {
        return m;
    }

    m = node->data;
    int lm = INT_MIN;
    int lr = INT_MIN;

    if (node->left != NULL)
    {
        int temp = maximum(node->left);

        lm = max(lm, temp);
    }

    if (node->right != NULL)
    {
        int temp = maximum(node->right);

        lr = max(lr, temp);
    }

    return max(m, max(lm, lr));
}

int sum(Node *root)
{

    // write your code here
    int total = 0;
    if (root == NULL)
    {
        return total;
    }

    int ls = 0;
    int rs = 0;

    if (root->left)
    {
        ls = sum(root->left);
    }

    if (root->right)
    {
        rs = sum(root->right);
    }

    return ls + rs + root->data;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        if (temp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(temp);
        }
    }

    Node *root = constructTree(arr);

    int sz = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout << sz << endl;
    cout << sm << endl;
    cout << max << endl;
    cout << ht << endl;
}