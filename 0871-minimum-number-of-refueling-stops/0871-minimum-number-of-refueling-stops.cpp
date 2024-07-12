class Solution {
// private:
//     int dp[501][1000000];
//     int solve(int i,int last,int target, int currFuel, vector<vector<int>>& stations, int n){
//         if(currFuel < 0) return INT_MAX;
//         if(i == n){
//             return (currFuel >= target - last) ? 0 : INT_MAX;
//         }

//         if(dp[i][currFuel] != -1) return dp[i][currFuel];

//         int dist = stations[i][0] - last;
//         int stop = INT_MAX;
//         if(currFuel >= dist){
//             stop = solve(i+1,stations[i][0],target,currFuel-dist+stations[i][1],stations,n);
//             if(stop != INT_MAX) stop += 1;
//         }
//         int notStop = solve(i+1,last,target,currFuel,stations,n);

//         return dp[i][currFuel] = min(stop,notStop);
//     }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // int n = stations.size();
        // memset(dp,-1,sizeof(dp));
        // int res = solve(0,0,target,startFuel,stations,n);
        // return res == INT_MAX ? -1 : res;
        
        int currSt = startFuel;
        int noOfStops = 0;
        priority_queue<int> pq;//maxHeap use karenge fuel store k liye
        for(auto &station : stations){
            int nextSt = station[0];
            int fuel = station[1];
            while(currSt < nextSt){
                if(pq.empty()) return -1;
                int temp = pq.top();
                pq.pop();
                currSt += temp;
                noOfStops++;
            }
            pq.push(fuel);
        }
        while(currSt < target){
            if(pq.empty()) return -1;
            int temp = pq.top();
            pq.pop();
            currSt += temp;
            noOfStops++;
        }
        return noOfStops;
    }
};