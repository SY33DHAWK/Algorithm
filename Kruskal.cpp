#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int>>> G;   // w, (u, v)
vector<pair<int, pair<int, int>>> MST; // MST edges
int vertex, edge;
int *parent;
void make_set()
{
    parent = new int[vertex];
    for (int i = 0; i < vertex; i++)
    {
        parent[i] = i;
    }
}
void print_parent()
{
    cout << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << parent[i] << "\t";
    }
}
int find_set(int u)
{
    if (u == parent[u])
        return u;
    else
        return find_set(parent[u]);
}
void union_set(int u, int v)
{
    parent[u] = parent[v];
}
int main()
{
    cout << "No of Vertex: ";
    cin >> vertex;
    cout << "No of Edge: ";
    cin >> edge;
    int u, v, w;
    cout << "Enter edge with weight (u v w):" << endl;
    for (int e = 1; e <= edge; e++)
    {
        cin >> u >> v >> w;
        G.push_back(make_pair(w, make_pair(u, v)));
    }
    // ------Kruskal's Algorithm-------
    make_set();
    print_parent();
    sort(G.begin(), G.end());
    cout << "\nThe edges sorted by weight are: " << endl;
    for (auto edge : G)
    {
        cout << "(" << edge.second.first << "," << edge.second.second << ") = " << edge.first << endl;
    }
    int u_loc, v_loc;
    int sum = 0;
    for (int i = 0; i < edge; i++)
    {
        u_loc = find_set(G[i].second.first);
        v_loc = find_set(G[i].second.second);
        if (u_loc != v_loc)
        {
            MST.push_back(G[i]);
            union_set(u_loc, v_loc);
            sum += G[i].first;
            cout << "\nParent array after adding edge ("
<< G[i].second.first << "," << G[i].second.second << ") = " << G[i].first << ":";
            print_parent();
        }
    }
    // Print MST
    cout << "\n\nMinimum Spanning Tree (MST):" << endl;
    for (int i = 0; i < MST.size(); i++)
    {
        cout << "(" << MST[i].second.first << "," << MST[i].second.second << ") = " << MST[i].first << endl;
    }
    // Print the sum of weights in MST
    cout << "\nTotal weight of MST: " << sum << endl;
    return 0;
}