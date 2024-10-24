class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        long long ans = 1;
        vector<int> neg;
        bool flag = false;
        int cnt = -1;
        for(auto num : nums){
            if(num > 0){
                cnt++;
                ans *= num;
            }
            else if(num < 0){
                neg.push_back(num);
            }
            else{
                flag = true;
            }
        }
        sort(neg.begin(),neg.end());
        int n = neg.size();
        long long val = -1;
        if(n>1){
            val = 1;
            for(int i=0;i<n-1;i++){
                val *= neg[i];
            }
            if(n%2 == 0)    val *= neg[n-1];
        }
        if(val != -1) ans *= val;
        if(ans == 1 && cnt == -1 && flag && val == -1){
            return 0;
        }
        return ans;
    }
};