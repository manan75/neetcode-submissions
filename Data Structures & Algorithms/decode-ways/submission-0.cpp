class Solution {
public:
    int numDecodings(string s) {
        
     map<string, char> mp = {
    {"1", 'A'},  {"2", 'B'},  {"3", 'C'},  {"4", 'D'},
    {"5", 'E'},  {"6", 'F'},  {"7", 'G'},  {"8", 'H'},
    {"9", 'I'},  {"10", 'J'}, {"11", 'K'}, {"12", 'L'},
    {"13", 'M'}, {"14", 'N'}, {"15", 'O'}, {"16", 'P'},
    {"17", 'Q'}, {"18", 'R'}, {"19", 'S'}, {"20", 'T'},
    {"21", 'U'}, {"22", 'V'}, {"23", 'W'}, {"24", 'X'},
    {"25", 'Y'}, {"26", 'Z'}
};
        int n  = s.size();
        vector<int> dp (n,-1);

        int ans = solve(dp,0,s,mp);
        return ans;
        
    }

    int solve(vector<int> & dp, int index, string &s, map<string,char> &mp){

        if(index>=s.size()){
            return 1;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        string c="";
        c+= s[index];
        int oneStep = 0;
        int twoStep = 0;
        if(mp.find(c)!=mp.end()){
            oneStep = solve(dp,index+1,s,mp);
        }

        if(index+1< s.size()){
            c+=s[index+1];
            if(mp.find(c)!=mp.end()){
                twoStep = solve(dp,index+2,s,mp);
            }
        }

        return dp[index]= oneStep+ twoStep;
    }
};
