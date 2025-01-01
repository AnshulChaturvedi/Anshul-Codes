class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int zeroCnt = 0;
        int oneCnt = count(s.begin(),s.end(),'1');

        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '1') oneCnt--;
            else zeroCnt++;
            ans = max(ans,zeroCnt + oneCnt);
        }
        return ans;
    }
};