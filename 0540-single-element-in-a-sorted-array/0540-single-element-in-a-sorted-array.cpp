class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int s = 0;
        int e = n-1;
        while(s<e){
            int mid = s + (e-s)/2;

            bool isEven; // to find that is no. of elements to right of mid is odd or even
            if((e-mid)%2 == 0){
                isEven = true;
            }
            else{
                isEven = false;
            }

            if(nums[mid] == nums[mid+1]){
                if(isEven){
                    s = mid + 2;
                }
                else{
                    e = mid - 1;
                }
            }
            else{// if nums[mid] != nums[mid + 1]
                if(isEven){
                    e = mid;
                }
                else{
                    s = mid + 1;
                }
            }
        }
        return nums[e];
    }
};