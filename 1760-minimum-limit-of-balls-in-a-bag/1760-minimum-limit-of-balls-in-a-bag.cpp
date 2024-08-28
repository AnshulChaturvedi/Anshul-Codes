class Solution {
public:
    bool isPossible(int maxBalls,vector<int>& nums, int maxOps){
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxBalls){
                cnt += (nums[i]-1)/maxBalls ;
                if(cnt > maxOps) return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOps) {
        int n = nums.size();
        int s = 1, e = *max_element(nums.begin(),nums.end());
        int ans = e;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(mid,nums,maxOps)){
                ans = min(ans,mid);
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};