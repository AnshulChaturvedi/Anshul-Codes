class Solution {
private:
    bool isPossible(vector<int>& nums, int k, int maxSum){
        int currSum = 0;
        int size = 1;
        for(int i=0;i<nums.size();i++){
            if(currSum + nums[i] <= maxSum){
                currSum += nums[i];
            }
            else{
                size++;
                currSum = nums[i];
                if(size > k) return false;
            }
        }
        return size <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;

        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);

        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(nums,k,mid)){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return s;
    }
};