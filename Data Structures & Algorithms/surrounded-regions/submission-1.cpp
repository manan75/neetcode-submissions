class Solution {
public:
    int n =0;
    int m =0;
    void solve(vector<vector<char>>& board) {
        n = board.size();
         m = board[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='O'){
                    bool surr = bfs(i,j,board,visited);
                    if(surr){
                        for(int k =0;k<n;k++){
                            for(int l =0;l<m;l++){
                                if(visited[k][l]==1){
                                    board[k][l]='X';
                                }
                            }
                        }
                    }
                   visited = vector<vector<int>>(n, vector<int>(m, 0));
                }
            }
        }

    }
    
        bool bfs(int i ,int j, vector<vector<char>> &board, vector<vector<int>> &visited){
            queue<pair<int,int>> q;
            if(i==0 || i==n-1 || j==0 || j==m-1)return false;
            visited[i][j]=1;
            q.push({i,j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                int row []= {-1,0,1,0};
                int col []={0,-1,0,1};
                for(int k =0;k<4;k++){
                    int r = x+row[k];
                    int c = y+ col[k];
                    if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==0 && board[r][c]=='O'){
                        if(r==0 || r==n-1 || c==0 || c==m-1){
                            return false;
                        }
                        visited[r][c]=1;
                        q.push({r,c});
                    }
                }
            }
            return true;
        }
};
