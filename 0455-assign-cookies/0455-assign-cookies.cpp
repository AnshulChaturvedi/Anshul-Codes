class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gsize = g.size();
        int ssize = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cookie = ssize-1;
        int child = gsize-1;
        int ans = 0;
        while(cookie >= 0 && child >=0){
            if(s[cookie] >= g[child]){
                ans++;
                cookie--;
                child--;
            }
            else{
                child--;
            }
        }
        return ans;
    }
};