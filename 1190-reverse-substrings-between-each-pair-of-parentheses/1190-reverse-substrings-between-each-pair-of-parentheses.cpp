class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(res.size());
            }
            else if(s[i] == ')'){
                int l = st.top();
                st.pop();
                reverse(res.begin()+l,res.end());
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};