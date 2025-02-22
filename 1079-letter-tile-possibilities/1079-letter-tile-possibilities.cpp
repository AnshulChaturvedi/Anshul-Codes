class Solution {
public:
    int solve(vector<int> &freq){
        int ans = 0;
        for(char c ='A'; c <= 'Z'; c++){
            if(freq[c-'A'] > 0){
                ans++;
                freq[c-'A']--;
                ans += solve(freq);
                freq[c-'A']++;
            }
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(auto &c : tiles)
            freq[c-'A']++;
        return solve(freq);
    }
};