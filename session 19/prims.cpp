#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int spanningTree(int V, vector<vector<int>>& edges)
{
    int e = edges.size();

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<bool> vis(V, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0,0});

    int mincost = 0;

    while(!pq.empty())
    {
        int wt = pq.top().first;
        int u  = pq.top().second;
        pq.pop();

        if(vis[u]) continue;

        vis[u] = true;
        mincost += wt;

        for(auto &edge : adj[u])
        {
            int nextwt = edge.first;
            int v = edge.second;

            if(!vis[v])
                pq.push({nextwt, v});
        }
    }

    return mincost;
}

int main()
{
    int V = 3;

    vector<vector<int>> edges = {
        {0,1,5},
        {1,2,4},
        {0,2,6}
    };

    cout << spanningTree(V, edges) << endl;
}