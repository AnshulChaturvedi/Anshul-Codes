class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto num : nums){
            if(num < k) return -1;
            if(num > k) st.insert(num);
        }
        if(st.size() == 0) return 0;
        return st.size();
    }
};