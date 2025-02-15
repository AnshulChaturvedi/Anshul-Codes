class Solution {
public:
    bool check(int i, int currSum, string s, int num){
        if(i >= s.length()) return currSum == num;
        if(currSum > num) return false;
        bool poss = false;
        for(int j=i; j<s.length(); j++){
            string sub = s.substr(i, j-i+1);
            int val = stoi(sub);
            poss = poss || check(j+1, currSum+val, s, num);
            if(poss) return true;
        }
        return poss;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for(int i=1; i<=n; i++){
            int sq = i*i;
            string s = to_string(sq);
            if(check(0, 0, s, i)){
                res += sq;
            }
        }
        return res;
    }
};