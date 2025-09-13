class Solution {
public:
    string encode(int i, vector<int>& needs){
        string res = to_string(i) + "|";
        for(auto &it : needs) res += to_string(it) + ',';
        return res;
    }

    int n;
    unordered_map<string, int> memo;
    int solve(int i, vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        string key = encode(i, needs);
        if(memo.find(key) != memo.end()) return memo[key];
        if(i == special.size()){
            int val = 0;
            for(int j=0; j<n; j++){
                val += price[j]*needs[j];
            }
            return val;
        }
        int skip = solve(i+1, price, special, needs);
        bool flag = true; //can take
        // vector<int>copy=needs;
        for(int k=0; k<n; k++){
            if(special[i][k] > needs[k]){
                flag = false;
                break;
            }
        }
        int take = INT_MAX;
        if(flag){
            vector<int>copy=needs;
            for(int k=0; k<n; k++){
                needs[k]-=special[i][k];
            }
            take = solve(i, price, special, needs) + special[i][n];
            needs=copy;
        }
        // needs=copy;
        return memo[key] = min(take, skip);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        return solve(0,price,special,needs);
    }
};