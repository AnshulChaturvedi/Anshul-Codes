class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;

        unordered_set<int> st(nums.begin(),nums.end());
        int maxLen = 1;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1) == st.end()){
                int len = 1;
                while(st.find(nums[i]+len) != st.end()){
                    len++;
                }
                maxLen = max(maxLen,len);
            }
        }
        return maxLen;
    }
};