class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+n-1;j++){
                int idx = j%n;
                if(nums[idx] > nums[i]){
                    ans[i] = nums[idx];
                    break;
                }
            }
        }
        return ans;
    }
};