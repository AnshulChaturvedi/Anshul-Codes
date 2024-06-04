class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for(auto ch : s){
            mpp[ch]++;
        }
        int ans = 0;
        bool flag = false;
        for(auto it : mpp){
            if(it.second%2 == 0){
                ans += it.second;
            }
            else{
                if(it.second > 1){
                    ans = ans + (it.second/2)*2;
                }
                flag = true;
            }
        }

        if(flag){
            return ans + 1;
        }
        return ans;
    }
};