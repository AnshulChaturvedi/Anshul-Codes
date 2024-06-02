class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[s] <= nums[mid]){//that is left part is sorted
                if(target <= nums[mid] && target >= nums[s]){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            else{//right part is sorted
                if(target <= nums[e] && target >= nums[mid]){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};