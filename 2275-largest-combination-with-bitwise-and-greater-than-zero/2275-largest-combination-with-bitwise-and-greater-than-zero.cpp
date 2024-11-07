class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int bitPos=0; bitPos<32; bitPos++){
            int cnt = 0;
            for(auto num : candidates){
                if((num & (1<<bitPos)) != 0){
                    cnt++;
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};