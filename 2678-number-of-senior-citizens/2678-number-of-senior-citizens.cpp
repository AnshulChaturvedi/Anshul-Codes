class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i=0;i<details.size();i++){
            int val = (details[i][11]-'0')*10 + (details[i][12]-'0');
            if(val > 60) cnt++;
        }
        return cnt;
    }
};