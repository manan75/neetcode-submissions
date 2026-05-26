class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //try all combinations of the words in the vector
        vector<int>dp(s.size(),-1);
        bool ans = solve(s,wordDict,0,dp);
        return ans;
    }
    bool solve(string &s, vector<string> & wordDict, int ind,vector<int> &dp){
        if(ind == s.size()){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i =0;i<wordDict.size();i++){
            int len = wordDict[i].size();
            if(ind+len<=s.size()){
                if(s.substr(ind,len)==wordDict[i]){
                    if(solve(s,wordDict, ind+len,dp)){
                        return dp[ind]=true;
                    }
                }
            }
        }
        return dp[ind]=false;
    }
};
