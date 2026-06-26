class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //start from the treasure, push all treasures and run a multi source bfs
        //level order bfs
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int dist = 1;
        while(!q.empty()){
            int s = q.size();
            for(int i =0;i<s;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                int row[]={1,0,-1,0};
                int col[]={0,-1,0,1};
                for(int k=0;k<4;k++){
                    int r = x + row[k];
                    int c = y + col[k];
                    if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && grid[r][c]!=-1){
                        if(grid[r][c]==2147483647){
                            grid[r][c]=dist;
                        }
                        visited[r][c]=1;
                        q.push({r,c});
                    }
                }
            }
            dist++;
        }

    }
};
