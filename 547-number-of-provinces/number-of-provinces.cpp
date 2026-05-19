class Solution {
public:
void dfs(unordered_map<int,vector<int>>&adjList,unordered_map<int,bool>&visited,int src){
    visited[src]=true;
    for(auto ng:adjList[src]){
        if(!visited[ng]){
            dfs(adjList,visited,ng);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected){
        unordered_map<int,vector<int>>adjList;
        queue<int>q;
        int n=isConnected.size();
         for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (isConnected[u][v] == 1 && u != v) {
                    adjList[u].push_back(v);
                    adjList[v].push_back(u);
                }
            }
        }
       unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
     int count=0;
        for(int i=0;i<n;i++){

        if(!visited[i]){
            dfs(adjList,visited,i);
            count++;
        }

        }


return count;
        
    }
};