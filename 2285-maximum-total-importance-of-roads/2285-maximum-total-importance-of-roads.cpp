class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n);
        for(auto &num : roads){
            for(auto &it: num){
                deg[it]++;
            }
        }
        sort(deg.begin(),deg.end());
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += (long long)(i+1)*deg[i];
        }
        return sum;
    }
};