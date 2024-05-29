class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int cnt = 0,maxi = 0;

        for(int i=0;i<nums.size()-1;i++){
            int diff = nums[i+1]-nums[i];
            if(nums[i] != nums[i+1] && diff == 1){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else if(diff > 0){
                cnt = 0;
            }
        }
        maxi++;

        return maxi;

    }
};