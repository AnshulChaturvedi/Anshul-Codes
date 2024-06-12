class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0,cnt1 = 0,cnt2 = 0;

        for(auto &it:nums){
            if(it == 0)
                cnt0++;
            else if(it == 1)
                cnt1++;
            else
                cnt2++;
        }

        int index = 0;

        while(cnt0--){
            nums[index] = 0;
            index++;
        }

        while(cnt1--){
            nums[index] = 1;
            index++;
        }
        
        while(cnt2--){
            nums[index] = 2;
            index++;
        }
        
    }
};