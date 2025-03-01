class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adjList(V);
        for (const auto p: edges) {
            int f = p.first;
            int s = p.second;
            adjList[f].push_back(s);
            adjList[s].push_back(f);
        }
        
        return adjList;
    }
};
