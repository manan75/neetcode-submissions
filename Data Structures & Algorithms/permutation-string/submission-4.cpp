class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> p1;
        unordered_map<char,int> p2;
        for(char c: s1){
            p1[c]++;
        }
        int i=0;
        int j =0;
        while(i<s2.size()){
            p2[s2[i]]++;
            if((i-j)+1==s1.size()){
                if(p1==p2){
                    return true;
                }
                p2[s2[j]]--;
                if(p2[s2[j]]==0){
                    p2.erase(s2[j]);
                }
                j++;
            }
            i++;
        }
        return false;
    }
};
