#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
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

void levelOrder(Node *node)
{
    // write your code here
    queue<pair<Node *, int>> q;

    q.push(make_pair(node, 0));

    int l = 0;

    while (!q.empty())
    {

        pair<Node *, int> p = q.front();
        q.pop();

        if (l != p.second)
        {
            cout << endl;
            l = p.second;
        }

        cout << p.first->data << " ";

        if (p.first->left != NULL)
            q.push(make_pair(p.first->left, p.second + 1));

        if (p.first->right != NULL)
            q.push(make_pair(p.first->right, p.second + 1));
    }

    return;
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
    levelOrder(root);
}