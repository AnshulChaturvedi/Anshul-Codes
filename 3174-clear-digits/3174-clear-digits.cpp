class Solution {
public:
    string clearDigits(string s) {
        string ans;
        stack<char> st;
        for(auto ch : s){
            if(ch >= '0' && ch <= '9') st.pop();
            else st.push(ch);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};