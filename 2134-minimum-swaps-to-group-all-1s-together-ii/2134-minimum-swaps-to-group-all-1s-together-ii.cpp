class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(auto &it : nums){
            if(it == 1) k++;
        }
        int ans = 1e9;
        int cnt = 0;
        for(int i=0;i<k;i++){
            if(nums[i] == 1) cnt++;
        }
        int forCircular = cnt;
        ans = min(ans,k-cnt);
        for(int i=k;i<n;i++){
            if(nums[i] == 1) cnt++;
            if(nums[i-k] == 1) cnt--;
            ans = min(ans,k-cnt);
        }
        int i=k-1,j=n-1;
        while(i>0){
            forCircular -= nums[i--];
            forCircular += nums[j--];
            ans = min(ans,k-forCircular);
        }
        return ans;
    }
};