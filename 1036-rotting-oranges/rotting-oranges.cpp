class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int time=0;
        int fresh=0;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty() && fresh>0){
            int sz=q.size();
            while(sz--){
                auto [row,col]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nrow=row+drow[k];
                    int ncol=col+dcol[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && (grid[nrow][ncol]==1)){
                        grid[nrow][ncol]=2;
                        fresh--;
                        q.push({nrow,ncol});
                    }
                }
            }
            time++;

        }
        return fresh==0 ? time : -1; 
    }
};