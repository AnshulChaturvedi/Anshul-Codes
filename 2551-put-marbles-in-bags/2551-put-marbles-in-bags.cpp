class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == n) return 0;
        // long long endValues = weights[0] + weights[n-1];
        // k ==> select k-1 slots
        vector<int> wts;
        for(int i=1; i<n; i++){
            int val = weights[i-1] + weights[i];
            wts.push_back(val);
        }
        sort(wts.begin(), wts.end());
        long long maxi = 0, mini = 0;
        for(int i=0; i<k-1; i++){
            mini += wts[i];
        }
        sort(wts.begin(), wts.end(),greater<int>());
        for(int i=0; i<k-1; i++){
            maxi += wts[i];
        }
        // mini += endValues;
        // maxi += endValues;
        return maxi-mini;
    }
};