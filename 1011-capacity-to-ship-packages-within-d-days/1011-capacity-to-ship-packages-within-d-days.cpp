class Solution {
private:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int totalDays = 1;
        int currWeight = 0;
        for(int i=0;i<weights.size();i++){
            if(currWeight + weights[i] > capacity){
                totalDays++;
                currWeight = weights[i];
                if(totalDays > days) return false;
            }
            else{
                currWeight += weights[i];
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxSum = accumulate(weights.begin(),weights.end(),0);
        int maxi = *max_element(weights.begin(),weights.end());
        
        int s = maxi;
        int e = maxSum;
        int ans = maxSum;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(weights,days,mid)){
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