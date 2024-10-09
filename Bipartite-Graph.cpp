class Solution {
private:
    bool dfs(int node,int col,int color[],vector<vector<int>>&graph){
        color[node] = col;
        // traverse all the neighbouring nodes
        for(auto neighbour:graph[node]){
            if(color[neighbour] == -1){
                if(dfs(neighbour,!col,color,graph) == false) return false;
            }
            else if(color[neighbour] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for(int i=0;i<V;i++){
            color[i] = -1;
        }
        for(int i = 0;i<V;i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
    return true;  
    }
};