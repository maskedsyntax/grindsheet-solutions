#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        queue<int> qu;
        qu.push(0);
        vector<int> vis(n, 0);
        vis[0] = 1;
        vector<int> ans;

        while(!qu.empty()) {
            const auto node = qu.front();
            qu.pop();
            ans.push_back(node);

            for (const auto el: adj[node]) {
                if (!vis[el]) {
                    qu.push(el);
                    vis[node] = 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}