class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp % 2 == 1) {
                res = ((res * base) % MOD);
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int cntPrimes(int num){
        int cnt = 0;
        if(num % 2 == 0){
            cnt++;
            while(num % 2 == 0) num /= 2;
        }
        for(int i=3; i <= sqrt(num); i+=2){
            if(num % i == 0){
                cnt++;
                while(num % i == 0) num /= i;
            }
        }
        if(num > 2) cnt++;
        return cnt;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scr(n);
        for(int i=0; i<n; i++){
            scr[i] = cntPrimes(nums[i]);
        }
        vector<int> nxtIdx(n,n);
        vector<int> prevIdx(n,-1);
        stack<int> decScore;
        for(int i=0; i<n; i++){
            while(!decScore.empty() && scr[decScore.top()] < scr[i]){
                int topIdx = decScore.top();
                decScore.pop();
                nxtIdx[topIdx] = i;
            }
            if(!decScore.empty()){
                prevIdx[i] = decScore.top();
            }
            decScore.push(i);
        }
        vector<long long> subArrays(n);
        for(int i=0; i<n; i++){
            subArrays[i] = (long long)(nxtIdx[i]-i)*(i-prevIdx[i]);
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        long long score = 1;
        while(k > 0){
            auto [num, index] = pq.top();
            pq.pop();
            long long operation = min((long long)k, subArrays[index]);
            score = (score * power(num, operation)) % MOD;
            k -= operation;
        }
        return score;
    }
};