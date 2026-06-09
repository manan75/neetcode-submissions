class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;

        for(char c : t)
            mp[c]++;

        int need = mp.size();

        int i = 0, j = 0;
        int ans = INT_MAX;
        string res;

        while(i < s.size()) {

            if(mp.find(s[i]) != mp.end()) {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    need--;
            }

            while(need == 0) {

                if(i - j + 1 < ans) {
                    ans = i - j + 1;
                    res = s.substr(j, ans);
                }

                if(mp.find(s[j]) != mp.end()) {
                    mp[s[j]]++;
                    if(mp[s[j]] == 1)
                        need++;
                }
                j++;
            }

            i++;
        }

        return ans == INT_MAX ? "" : res;
    }
};