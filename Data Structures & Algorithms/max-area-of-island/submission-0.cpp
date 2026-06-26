class Solution {
public:
    int n;
    int m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
         n = grid.size();
        m = grid[0].size();
        int maxi = 0;
        vector<vector<int>> visited(n, vector<int> (m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                   int islands= bfs(i,j, visited,grid);
                    maxi = max(maxi,islands);
                }
            }
        }
        return maxi;
    }

    int bfs(int i ,int j , vector<vector<int>> &visited, vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;
        int islands = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int row []= {0,-1,0,1};
            int col []= {1,0,-1,0};
            for(int k =0;k<4;k++){
                int r = x + row[k];
                int c = y+ col[k];
                if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && grid[r][c]==1){
                    visited[r][c]=1;
                    islands++;
                    q.push({r,c});
                }
            }
        }
        return islands;
    }
};
