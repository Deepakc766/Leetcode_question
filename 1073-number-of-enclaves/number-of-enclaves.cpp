class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0|| j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        visited[i][j]=true;
                    }
                }
            }

        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [row , col]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nrow=row+drow[k];
                    int ncol=col+dcol[k];
                    if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                        q.push({nrow,ncol});
                        visited[nrow][ncol]=true;
                    }
                }
            }

        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
            if(grid[i][j]==1 && visited[i][j]==0){
                    cnt++;
                
                }
            }

        }

       return cnt; 
    }
};