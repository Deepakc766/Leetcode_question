class Solution {
public:
bool iscycle(int src,unordered_map<int,bool> &visited,unordered_map<int,bool> &trackdfs,unordered_map<int,list<int>> &adjlist){
    visited[src]=true;
    trackdfs[src]=true;
    for(auto ng:adjlist[src]){
        if(!visited[ng]){
            if(iscycle(ng,visited,trackdfs,adjlist)){
                return true;
            }
        }else if(trackdfs[ng]){
            return true;
        }
    }
    trackdfs[src]=false;
    return false;
}
    bool canFinish(int n, vector<vector<int>>& p) {
        //if there is cycle then course cannot be completed 
        unordered_map<int,list<int>>adjlist;
        for(auto it:p){
            adjlist[it[1]].push_back(it[0]);

        }
        unordered_map<int,bool>visited;
        unordered_map<int,bool>trackdfs;
        
        bool ans=false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
            ans=iscycle(i,visited,trackdfs,adjlist);
            if(ans)return false;
            }
        }
        return true;

    }
};