#include <iostream>
#include <vector>
using namespace std;

void printHamilton(vector<vector<int>>& graph, int index, int n, int count, vector<int>& ans, vector<bool>& b, int src) {
    if (count == n - 1) {
        char c = '.';
        for (int i = 0; i < graph[index].size(); i++) {

            if (graph[index][i] == src) {
                c = '*';
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << c << endl;
        return;
    }



    for (int i = 0; i < graph[index].size(); i++) {

        int child = graph[index][i];
        if(b[child] == false) {
            b[child] = true;
            ans.push_back(child);

            printHamilton(graph, child, n, count + 1, ans, b, src);

            ans.pop_back();
            b[child] = false;
        }
    }

    return;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n, vector<int>());

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >>c;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin >> src;

    vector<bool> b(n, false);
    vector<int> ans;
    ans.push_back(src);
    b[src] = true;
    printHamilton(v, src, n, 0, ans, b, src);

}