class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<long long,long long> mpp;
        for(auto num : nums) mpp[num]++;
        int cnt = 0;
        while(!mpp.empty() && mpp.begin()->first < k){
            auto it1 = mpp.begin();
            long long num1 = it1->first;
            if(it1->second >= 2){
                it1->second -= 2;
                if(it1->second == 0){
                    mpp.erase(it1);
                }
                long long newVal = 3 * num1;
                mpp[newVal]++;
            }
            else{
                auto it2 = next(it1);
                long long num2 = it2->first;
                it1->second--;
                if(it1->second == 0){
                    mpp.erase(it1);
                }
                it2->second--;
                if(it2->second == 0){
                    mpp.erase(it2);
                }
                long long mini = min(num1, num2);
                long long maxi = max(num1, num2);
                long long val = mini * 2 + maxi;
                mpp[val]++;
            }
            cnt++;
        }
        return cnt;
    }
};