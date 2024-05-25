class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> val;
        int last = nums[0];
        val.push_back(last);
        for(int i=1;i<nums.size();i++){
            if(nums[i] != last)
                val.push_back(nums[i]);
                last = nums[i];
        }
        for(int i=0;i<val.size();i++){
            nums[i] = val[i];
        }
        return val.size();
    }
};