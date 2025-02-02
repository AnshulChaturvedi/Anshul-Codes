class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')){
            if(token == "." || token == "") continue;
            if(token == ".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(token);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = '/' + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};