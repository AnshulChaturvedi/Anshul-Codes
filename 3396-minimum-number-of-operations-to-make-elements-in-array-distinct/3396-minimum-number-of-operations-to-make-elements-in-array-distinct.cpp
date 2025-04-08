class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2){
            return (nums[0] != nums[1]) ? 0 : 1;
        }
        int cnt = 0;
        unordered_map<int,int> mpp;
        for(auto num : nums) mpp[num]++;
        int i=0, j=0;
        while(j < nums.size()){
            if(mpp[nums[j]] > 1){
                int k = 3;
                while(k-- && i<nums.size()){
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                    i++;
                }
                j = i;
                cnt++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};