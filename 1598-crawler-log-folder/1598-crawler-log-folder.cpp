class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto &it : logs){
            if(st.empty() && it == "../"){
                continue;
            }
            else if(!st.empty() && it == "../"){
                st.pop();
            }
            else if(it == "./"){
                continue;
            }
            else{
                st.push(it);
            }
        }
        return st.size();
    }
};