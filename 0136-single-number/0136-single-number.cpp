class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum = sum^it;
        }
        return sum;
    }
};