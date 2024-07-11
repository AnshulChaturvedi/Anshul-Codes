class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> mapping(n);
        //for mapping we are gona use stack 
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int idx = st.top();
                st.pop();
                mapping[i] = idx;
                mapping[idx] = i;
            }
        }
        string ans = "";
        int flag = 1;
        for(int i=0;i<n;i+=flag){
            if(s[i] == '(' || s[i] == ')'){
                flag = -flag;
                i = mapping[i];
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};