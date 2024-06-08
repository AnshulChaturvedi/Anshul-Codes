class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        int i=0, j=0;

        vector<bool> vis(256,false);

        while(j<n){
            if(vis[s[j]] == true){
                while(vis[s[j]] == true){
                    vis[s[i]] = false;
                    i++;
                }
            }
            vis[s[j]] = true;
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};