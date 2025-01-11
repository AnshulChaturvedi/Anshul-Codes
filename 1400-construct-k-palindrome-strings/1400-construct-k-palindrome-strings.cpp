class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        vector<int> freq(26,0);
        for(auto &c : s){
            freq[c-'a']++;
        }
        int oddCnt = 0;
        for(auto &it : freq){
            oddCnt += it&1;
        }
        return oddCnt <= k;
    }
};