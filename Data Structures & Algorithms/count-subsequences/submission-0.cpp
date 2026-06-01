class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int> (t.size(),-1));
        int ans =solve(dp,s,t,s.size()-1,t.size()-1);
        return ans;
    }
    int solve(vector<vector<int>> &dp, string &s, string &t, int i ,int j){
        if(j<0){
            return 1;
        }
        if(i<0 ){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int a1 =0;
        if(s[i]==t[j]){
            //take or dont 
            a1 = solve(dp,s,t,i-1,j-1);
        }
        int a2 = solve(dp,s,t,i-1,j);
        return dp[i][j]= a1+a2;
    }
};
