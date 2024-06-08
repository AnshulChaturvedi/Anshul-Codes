class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;
        int leftSum = 0, rightSum = 0;

        for(int i=0;i<k;i++){
            leftSum += nums[i];
        }

        maxSum = max(maxSum,leftSum);

        int rightIndex = n-1;
        int leftIndex = k-1;

        for(int i=leftIndex;i>=0;i--){
            leftSum -= nums[i];
            rightSum += nums[rightIndex];
            rightIndex--;

            maxSum = max(maxSum,leftSum + rightSum);
        }

        return maxSum;
    }
};