void DFS(int node, vector<vector<int>> &edges, vector<int> &temp, vector<bool> &track)
{

    track[node] = true;

    temp.push_back(node);

    for (auto x : edges[node])
    {
        if (track[x] == false)
            DFS(x, edges, temp, track);
    }

    return;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edge)
{
    // Write your code here
    vector<vector<int>> edges(V, vector<int>(V));
    for (auto x : edge)
    {
        int a = x[0];
        int b = x[1];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<vector<int>> ans;
    vector<bool> track(V, false);
    vector<int> temp;

    for (int i = 0; i < V; i++)
    {
        if (track[i] == false)
        {
            DFS(i, edges, temp, track);

            ans.push_back(temp);

            temp.clear();
        }
    }

    return ans;
}