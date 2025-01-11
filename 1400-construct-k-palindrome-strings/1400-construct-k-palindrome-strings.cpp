class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        if(n == k) return true;
        //if(n>k)
        int cnt = 0;
        unordered_map<char,int> mpp;
        for(auto c : s) mpp[c]++;
        for(auto &it : mpp){
            if(it.second&1) cnt++;
        }
        if(cnt > k) return false;
        return true;
    }
};