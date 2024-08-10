class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        vector<int> copy = nums;
        for(auto &it : nums) copy.push_back(it);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <= copy[i]){
                st.pop();
            }
            if(i<n){
                ans[i] = (st.empty())? -1 : st.top();
            }
            st.push(copy[i]);
        }  
        return ans; 
    }
};