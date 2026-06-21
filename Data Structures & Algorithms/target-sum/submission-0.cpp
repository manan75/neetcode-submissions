class Solution {
public:
    int t=0;
    int s= 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        t=target;
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
        s=sum;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2*sum+1, INT_MIN));

        int ans = solve(dp,n-1,0,nums);
        return ans;
    }

    int solve(vector<vector<int>> &dp, int index, int curr, vector<int> &nums){

        if(index<0){
            if(curr==t)return 1;
            return 0;
        }
        if(dp[index][curr+s]!=INT_MIN){
            return dp[index][curr+s];
        }
        int add = solve(dp, index-1,curr+nums[index],nums);
        int sub = solve(dp,index-1, curr-nums[index],nums);

       return dp[index][curr +s]= add+sub;
    }
};
