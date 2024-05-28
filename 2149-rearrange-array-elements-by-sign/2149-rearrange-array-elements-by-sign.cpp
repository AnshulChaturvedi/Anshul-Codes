class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos=0,neg=1;
        //since positives will be on even and negatives will be on odd indexes
        vector<int> result(n);
        for(auto num : nums){
            if(num > 0){
                result[pos] = num;
                pos += 2;
            }
            else{
                result[neg] = num;
                neg += 2;
            }
        }
        return result;
    }
};