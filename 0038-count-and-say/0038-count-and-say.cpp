class Solution {
public:
    string RLE(string &s, int n){
        if(n == 1) return s;
        int m = s.length();
        string str = "";
        int i=0;
        while(i<m){
            int same = 0, j = i;
            while(s[j] == s[i] && j<m){
                j++;
                same++;
            }
            str += to_string(same) + s[i];
            i = j;
        }
        return RLE(str, n-1);
    }

    string countAndSay(int n) {
        string s = "1";
        if(n == 1) return s;
        return RLE(s, n);
    }
};