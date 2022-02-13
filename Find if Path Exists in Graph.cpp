#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    if (n == 1) {
        return true;
    }

    vector<vector<int>> adj(n);

    for (auto x : edges) {
        adj[x.at(0)].push_back(x.at(1));
        adj[x.at(1)].push_back(x.at(0));
    }

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int a = q.front();

        int i = 0;
        int size = adj[a].size();

        while (i < size) {

            int curr = adj[a].at(i);

            if (curr == destination)
                return true;

            if (visited[curr] == false) {
                q.push(curr);
                visited[curr] = true;
            }

            i++;
        }
        q.pop();
    }
    return false;
}

int main()
{
    int n,m;
    cin >> n >>m;

    vector<vector<int>> qn;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);

        qn.push_back(temp);
    }

    int s, d;
    cin >> s >> d;
    cout << validPath(n,qn,s,d) << endl;
    return 0;
}