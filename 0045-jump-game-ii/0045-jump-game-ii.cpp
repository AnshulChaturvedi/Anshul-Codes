class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        int jumps = 0;

        while(!q.empty()){
            int size = q.size();
            jumps++;
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(int j=1;j<=nums[node];j++){
                    int next = node + j;
                    if(next >= n-1){
                        return jumps;
                    }
                    if(!vis[next]){
                        q.push(next);
                        vis[next] = 1;
                    }
                }
            }
        }
        return -1;
    }
};