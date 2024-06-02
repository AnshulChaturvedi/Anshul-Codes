class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // return index if found, if not return ub;
        int s = 0;
        int e = nums.size()-1;
        int ub = nums.size();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= target){
                ub = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ub;
    }
};