class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //cnt num of dist elements greater than K
        // auto it = find(nums.begin(), nums.end(), k);
        // if(it == nums.end()) return -1;

        unordered_set<int> st;
        int lesser = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > k) st.insert(nums[i]);
            if(nums[i] < k) lesser++;
        }
        if(lesser == 0 && st.size() == 0) return 0;
        if(lesser > 0) return -1;
        return st.size();
    }
};