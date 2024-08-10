class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int val = nums[i];
            bool flag = false;
            for(int j=i+1;j<n;j++){
                if(nums[j] > val){
                    ans.push_back(nums[j]);
                    flag = true;
                    break;
                }
            }
            if(flag == true) continue;
            for(int j=0;j<i;j++){
                if(nums[j] > val){
                    ans.push_back(nums[j]);
                    flag = true;
                    break;
                }
            }
            if(flag == true) continue;
            ans.push_back(-1);
        }
        return ans;
    }
};