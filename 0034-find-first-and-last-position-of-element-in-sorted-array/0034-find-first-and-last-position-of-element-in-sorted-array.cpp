class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1,-1};

        int s = 0;
        int e = n-1;
        int start = n;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                start = mid;
                e = mid - 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        if(start == n){
            return {-1,-1};
        }

        s = 0;
        e = n-1;
        int end = n;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] > target){
                end = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        end = end - 1;

        return {start,end};
    }
};