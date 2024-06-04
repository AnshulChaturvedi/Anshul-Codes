using ll = long long;

class Solution {
public:
    int mySqrt(int x) {
        ll ans = 0;
        ll s = 1;
        ll e = x;
        while(s<=e){
            ll mid = s + (e-s)/2;
            if((ll)mid * mid == x){
                return mid;
            }
            else if((ll)mid * mid > x){
                e = mid - 1;
            }
            else{
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
};