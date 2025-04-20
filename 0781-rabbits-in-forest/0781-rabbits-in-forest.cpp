class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int> mpp;
        for(auto it : ans) mpp[it]++;
        int cnt = 0;
        for(auto &it : mpp){
            int val = it.first + 1;
            if(it.second == val) cnt += it.second;
            else if(it.second < val) cnt += val;
            else if(it.second > val){
                cnt += (it.second / val) * val;
                if(it.second % val) cnt += val;
            }
        }
        return cnt;
    }
};