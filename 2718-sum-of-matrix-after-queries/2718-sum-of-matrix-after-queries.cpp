class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowVisited(n,false);
        vector<bool> colVisited(n,false);

        long long rowUpdated = 0, colUpdated = 0;

        long long x = queries.size();
        long long sum = 0;

        for(long long i=x-1;i>=0;i--){

            bool row = (queries[i][0] == 0);
            long long idx = queries[i][1];
            long long val = queries[i][2];

            if(row){
                if(!rowVisited[idx]){
                    sum += (n-colUpdated)*val;
                    rowVisited[idx] = true;
                    rowUpdated++;
                }
            }
            else{
                if(!colVisited[idx]){
                    sum += (n-rowUpdated)*val;
                    colVisited[idx] = true;
                    colUpdated++;
                }
            }
        }
        return sum;
    }
};