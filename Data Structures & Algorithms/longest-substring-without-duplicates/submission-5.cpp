class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        unordered_map<char,int> mp;
        int i =0;
        int j =0;
        int ans =1;
        while(i<s.size()){
           char c = s[i];
           
            while(j<=i && mp[c]==1){
                mp[s[j]]--;
                j++;
                ans = max(ans, (i-j)+1);
            }
            mp[c]=1;
            ans = max(ans,(i-j)+1);
            i++;
        }
        return ans;
    }
};
