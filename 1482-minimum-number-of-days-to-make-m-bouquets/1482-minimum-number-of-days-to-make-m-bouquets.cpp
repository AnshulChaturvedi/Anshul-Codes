class Solution {
private:
    bool isPossible(vector<int>& bloomDay, int m, int k,int mid){
        int bouquets = 0;
        int flowers = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }
        return (bouquets >= m) ? true : false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;

        if(k == 1){
            sort(bloomDay.begin(),bloomDay.end());
            return bloomDay[m-1];
        }

         int maxi = *max_element(bloomDay.begin(), bloomDay.end());


        int s = 1;
        int e = maxi;
        int ans = maxi;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(bloomDay,m,k,mid)){
                ans = min(mid,ans);
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};