class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,int> mpp;
                //    digitSum, maxNum
        for(auto num : nums){
            int dsum = digitSum(num);
            if(mpp.find(dsum) != mpp.end()){
                ans = max(ans, mpp[dsum] + num);
                mpp[dsum] = max(mpp[dsum], num);
            }
            else{
                mpp[dsum] = num;
            }
        }
        return ans;
    }
};