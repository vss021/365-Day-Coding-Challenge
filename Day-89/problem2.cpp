#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    int unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        int ans = size[ulp_u] * size[ulp_v];
        if (ulp_u == ulp_v)
            return ans;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            edges[i][0] = wt;
            edges[i][1] = u;
            edges[i][2] = v;
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(n + 1);
        map<int, int> mp;
        int val = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int u = edges[i][1];
            int v = edges[i][2];
            int wt = edges[i][0];
            mp[wt] = ds.unionBySize(u, v) + val;
            val = mp[wt];
        }
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++)
        {
            auto it = mp.upper_bound(queries[i]);
            if (it != mp.begin())
            {
                it--;
                ans[i] = it->second;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example usage for maximumWeight function
    int n = 6;
    vector<vector<int>> edges = {{1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {4, 5, 4}, {5, 6, 7}};
    int q = 3;
    vector<int> queries = {3, 6, 8};
    vector<int> result = solution.maximumWeight(n, edges, q, queries);

    cout << "Maximum weights for queries:";
    for (int val : result)
    {
        cout << " " << val;
    }
    cout << endl;

    return 0;
}
