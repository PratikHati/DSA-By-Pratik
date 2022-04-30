#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;
    int wt = 0;


    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;

    }
};

void printDFSitterative(vector<vector<Edge>>& graph, int src, vector<bool>& b) {

    stack<string> st;
    st.push(to_string(src));

    while (!st.empty()) {
        string str = st.top();
        st.pop();

        char c =  str[str.length() - 1];
        int d = c - 48;

        if (b[d] == true) {
            continue;
        }

        b[d] = true;

        cout << d << "@" << str << endl;
        //visit all nbr

        for (int i = 0; i < graph[d].size(); i++) {

            int child = graph[d][i].nbr;

            if (b[child] == true) {
                continue;
            }
            string help = str + to_string(child);

            st.push(help);
        }
    }
}

int main() {

    int vtces;
    cin >> vtces;
    vector<vector<Edge>> graph(vtces, vector<Edge>());


    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v, w));
        graph[v].push_back(Edge(v, u, w));
    }

    int src;
    cin >> src;
    //write your code here 
    vector<bool> b(vtces, false);

    printDFSitterative(graph, src, b);


    return 0;
}