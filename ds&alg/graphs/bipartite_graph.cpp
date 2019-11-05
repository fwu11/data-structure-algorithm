// graph coloring
// dfs
// O(V+E)

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);
        
        for(int i = 0; i < n; i++)
            if(!colors[i] && !dfs(graph,colors,1,i))
                return false;
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int color, int node){
        if(colors[node]) return colors[node] == color;
        colors[node] = color;
        for(auto neighbor : graph[node]){
            if(!dfs(graph,colors,-color,neighbor)) return false;
        }
        return true;
    }
};