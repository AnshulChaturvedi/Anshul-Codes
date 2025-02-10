class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(auto ch : s){
            if(ch >= 'a' && ch <= 'z') ans += ch;
            else ans.pop_back();
        }
        return ans;
    }
};