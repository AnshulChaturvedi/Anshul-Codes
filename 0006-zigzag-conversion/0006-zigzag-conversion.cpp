class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;

        vector<string> r(min(n,(int)s.size()));
        int currRow = 0;
        bool goingDown = false;
        for(auto ch : s){
            r[currRow] += ch;
            if(currRow == 0 || currRow == n-1){
                goingDown = !goingDown;
            }
            currRow += (goingDown) ? 1 : -1;
        }
        string ans;
        for(auto &it : r){
            ans += it;
        }
        return ans;
    }
};