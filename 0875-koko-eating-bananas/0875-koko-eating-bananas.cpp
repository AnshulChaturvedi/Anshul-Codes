class Solution {
private:
    bool isPossible(int mid,vector<int> &piles,int h){
        long long timeRequired = 0;
        for(auto it : piles){
            timeRequired += (long long)(it+mid-1)/mid;
            if(timeRequired > h) return false;
        }
        return timeRequired <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxi = piles[0];
        for(auto it : piles){
            maxi = max(maxi,it);
        }
        if(h == n) return maxi;

        int ans = maxi;  
        int s = 1;
        int e = maxi;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(mid,piles,h)){
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