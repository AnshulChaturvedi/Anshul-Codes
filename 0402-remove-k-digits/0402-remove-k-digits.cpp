class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";

        string res = "";
        stack<int> st;
        st.push(num[0]-'0'); 
        for(int i=1;i<n;i++){
            while(!st.empty() && k>0 && st.top() > (num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(k--){
            st.pop();
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            res.push_back(st.top()+'0');
            st.pop();
        }
        while(res.size() > 0 && res.back() == '0') res.pop_back();
        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};