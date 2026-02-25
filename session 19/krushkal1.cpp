class DSU
{
public:
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionbysize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:

    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // 🔹 Convert {u, v, wt} → {wt, u, v}
        vector<vector<int>> temp;

        for (auto &it : edges)
            temp.push_back({it[2], it[0], it[1]});

        // 🔹 Sort by weight
        sort(temp.begin(), temp.end());

        DSU dsu(V);

        int mstweight = 0;

        for (auto &edge : temp)
        {
            int wt = edge[0];
            int u  = edge[1];
            int v  = edge[2];

            if (dsu.findUPar(u) != dsu.findUPar(v))
            {
                mstweight += wt;
                dsu.unionbysize(u, v);
            }
        }

        return mstweight;
    }
};