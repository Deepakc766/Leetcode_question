class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        //if there is cycle then course cannot be completed 
        unordered_map<int,list<int>>adjlist;
        for(auto it:p){
            adjlist[it[1]].push_back(it[0]);

        }
        unordered_map<int,int>indegree;
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto ng:adjlist[i]){
                indegree[ng]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);

        for(auto ng:adjlist[front]){
            indegree[ng]--;
            if(indegree[ng]==0){
                q.push(ng);
            }
        }
        }
      if(ans.size()!=n)return false;
        return true;

    }
};