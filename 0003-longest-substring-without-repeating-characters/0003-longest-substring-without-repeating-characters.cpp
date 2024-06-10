class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<bool> count(256,0);
        int i=0, j=0, maxLength = 0;
        while(j<n){
            while(count[s[j]] == true){
                count[s[i]] = false;
                i++;
            }
            count[s[j]] = true;
            maxLength = max(maxLength,j-i+1);
            j++;
        }
        return maxLength;
    }
};