class Solution {
public:
    bool isPossible(int mid,vector<int>& candies, long long k){
        long long cnt = 0;
        for(int i=0;i<candies.size();i++){
            cnt += (long long)(candies[i]/mid);
            if(cnt >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(),candies.end(),0LL);
        if(total < k) return 0;

        long long n = candies.size();
        long long maxi = *max_element(candies.begin(),candies.end());
        long long s = 1, e = maxi;
        long long ans = 0;
        while(s<=e){
            long long mid = s + (e-s)/2;
            if(isPossible(mid,candies,k)){
                ans = max(ans,mid);
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};