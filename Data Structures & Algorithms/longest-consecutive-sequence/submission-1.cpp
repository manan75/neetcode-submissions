class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
      
        for(int i =0;i<nums.size();i++){
                // if(mp[nums[i]]!=0)continue;
                mp[nums[i]]=1;
        }
        int res=0;
        for(int i =0;i<nums.size();i++){
            if(mp[nums[i]-1]!=1){
                int j = nums[i];
                int ans =1;
                while(true){
                    if(mp[j+1]!=1)break;
                    ans++;
                    j++;
                }
                res = max(ans,res);
            }
        }
        return res;
    }
};
