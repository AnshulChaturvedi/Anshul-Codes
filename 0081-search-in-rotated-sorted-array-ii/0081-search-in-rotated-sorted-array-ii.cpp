class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0,e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[s] == nums[mid] && nums[e] == nums[mid]){
                s++;
                e--;
            }
            else if(nums[s] <= nums[mid]){//left part is sorted
                if(target >= nums[s] && target <= nums[mid]){
                    e = mid -1;
                }
                else{
                    s = mid + 1;
                }
            }
            else{//right part is sorted
                if(target >= nums[mid] && target <= nums[e]){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
        }
        return false;
    }
};