class Solution {
private:
    int dp[31][3001];
    int solve(int i,int currSum,int reqSum,vector<int> &stones,int n){
        if(i >= n){
            return currSum;
        }
        if(dp[i][currSum] != -1) return dp[i][currSum];
        int pick = currSum;
        if(stones[i] + currSum <= reqSum){
            pick = solve(i+1,currSum+stones[i],reqSum,stones,n);
        }
        int notPick = solve(i+1,currSum,reqSum,stones,n);

        return dp[i][currSum] = max(pick,notPick);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin(),stones.end(),0);
        int reqSum = totalSum / 2;
        memset(dp,-1,sizeof(dp));
        int maxValEqualtolessThanTarget = solve(0,0,reqSum,stones,n);
        return totalSum - 2 * maxValEqualtolessThanTarget;
    }
};