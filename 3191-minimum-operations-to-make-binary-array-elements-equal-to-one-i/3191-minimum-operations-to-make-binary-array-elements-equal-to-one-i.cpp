class Solution {
private:
    void flipBits(vector<int> &nums,int i){
        for(int k=i;k<=i+2;k++){
            nums[k] = !nums[k];
        }
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0 && i<=n-3){
                flipBits(nums,i);
                cnt++;
            }
            else if(nums[i] == 0){
                return -1;
            }
        }
        return cnt;
    }
};