class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        sort(nums.begin(),nums.end());

        int len = 1, maxLen=1;

        for(int i=1;i<n;i++){
            int diff = nums[i]-nums[i-1];
            if(diff > 1){
                len = 1;
            }
            else{
                if(nums[i] != nums[i-1]) len++;
                maxLen = max(maxLen,len);
            }
        }
        return maxLen;
    }
};