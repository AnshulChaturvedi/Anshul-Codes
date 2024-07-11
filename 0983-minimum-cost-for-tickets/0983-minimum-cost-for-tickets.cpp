class Solution {
private:
    int dp[366];
    int solve(int i,vector<int>& days, vector<int>& costs,int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        //1 day pass
        int cost_1 = costs[0] + solve(i+1,days,costs,n);
        //7 day pass
        int j=i;
        int maxDays = days[i] + 7;
        while(j<n && days[j] < maxDays){
            j++;
        }
        int cost_7 = costs[1] + solve(j,days,costs,n);
        // 30 day pass
        j=i;
        maxDays = days[i] + 30;
        while(j<n && days[j] < maxDays){
            j++;
        }
        int cost_30 = costs[2] + solve(j,days,costs,n);

        return dp[i] = min({cost_1,cost_7,cost_30});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs,n);
    }
};