class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if( (s[i]=='{' || s[i]=='[' || s[i]=='(')){
                st.push(s[i]);
            }
            else if(st.empty()){
                return false;
            }
            else{
                char c;
                if(s[i]=='}') c= '{';
                if( s[i]==')') c= '(';
                if(s[i]==']') c= '[';
                    char p = st.top();
                     st.pop();
                    if(p!=c){ 
                        return false;
                    }
            }
        }
        if(st.empty())return true;
       return false;
    }
};
