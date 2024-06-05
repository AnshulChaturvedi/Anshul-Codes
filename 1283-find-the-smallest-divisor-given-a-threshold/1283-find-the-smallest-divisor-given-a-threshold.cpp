class Solution {
private:
    bool isPossible(vector<int>& nums, int threshold,int val){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/val);
        }
        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(),nums.end());
        int s = 1;
        int e = maxi;
        int ans = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(nums,threshold,mid)){
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