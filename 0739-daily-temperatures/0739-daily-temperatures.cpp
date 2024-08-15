class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> ans(n),ngtemp(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[st.top()]<=temp[i]){
                st.pop();
            }
            ngtemp[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(ngtemp[i] == n) ans[i] = 0;
            else ans[i] = ngtemp[i]-i;
        }
        return ans;
    }
};