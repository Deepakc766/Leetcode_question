class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph){
        unordered_map<int,vector<int>>adjList;
        queue<int>q;
        unordered_map<int,int>color;
        for(int u=0;u<graph.size();u++){
            color[u]=-1;
            for(int ng:graph[u]){
                adjList[u].push_back(ng);
            }    
        }
        for(int u=0;u<graph.size();u++){
        if(color[u]!=-1)continue;
        q.push(u);
        color[u]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto ng:adjList[node]){
                if(color[ng]==-1){
                    color[ng]=1-color[node];
                    q.push(ng);

                }else if(color[node]==color[ng]){
                    return false;
                }
            }
        }

        }
        

    return true;
    }
};