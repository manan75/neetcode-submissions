class Solution {
public:
    int change(int amount, vector<int>& coins) {

     vector<vector<int>> dp(coins.size(), vector<int> (amount+1,-1));

     int ans = solve(coins,amount,coins.size()-1, dp);
     return ans;
      
    }

    int solve(vector<int> & coins, int amount, int ind, vector<vector<int>> &dp){
        if(ind<0){
            return 0;
        }
        if(amount==0 ){
            return 1;
        }
        
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int take = 0;
        if(coins[ind]<=amount){
             take = solve(coins,amount-coins[ind], ind,dp);
        }
        int notTake = solve(coins,amount, ind-1,dp);

        return dp[ind][amount]= take+notTake;

    }
};
