class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int> st;
        for(auto &it : nums2){
            while(!st.empty() && st.top() < it){
                mpp[st.top()] = it;
                st.pop();
            }
            st.push(it);
        }
        vector<int> ans;
        for(auto &it : nums1){
            if(mpp.find(it) != mpp.end()){
                ans.push_back(mpp[it]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};