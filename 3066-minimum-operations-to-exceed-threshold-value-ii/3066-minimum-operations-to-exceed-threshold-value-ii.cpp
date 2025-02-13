class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // map<long long,long long> mpp;
        // for(auto num : nums) mpp[num]++;
        // int cnt = 0;
        // while(!mpp.empty() && mpp.begin()->first < k){
        //     auto it1 = mpp.begin();
        //     long long num1 = it1->first;
        //     if(it1->second >= 2){
        //         it1->second -= 2;
        //         if(it1->second == 0){
        //             mpp.erase(it1);
        //         }
        //         long long val = 3 * num1;
        //         mpp[val]++;
        //     }
        //     else{
        //         it1->second--;
        //         if(it1->second == 0){
        //             mpp.erase(it1);
        //         }
        //         auto it2 = next(it1);
        //         long long num2 = it2->first;
        //         it2->second--;
        //         if(it2->second == 0){
        //             mpp.erase(it2);
        //         }
        //         long long mini = min(num1, num2);
        //         long long maxi = max(num1, num2);
        //         long long val = mini * 2 + maxi;
        //         mpp[val]++;
        //     }
        //     cnt++;
        // }
        // return cnt;

        
        priority_queue<long long,vector<long long>,greater<long long>> pq(nums.begin(), nums.end());
        //min-heap --> min elements at the top
        int cnt = 0;
        while(pq.size() >= 2 && pq.top() < k){
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            long long val = min(num1, num2) * 2 + max(num1, num2);
            pq.push(val);
            cnt++;
        }
        return cnt;
    }
};