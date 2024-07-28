class Solution {
public:
    bool isPalindrome(string &str){
        int s = 0,e = str.size()-1;
        while(s<e){
            if(str[s] != str[e]) return false;
            s++;
            e--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        //generate all substr and then find if it is palindrome or not
        for(int i=0;i<n;i++){
            for(int len=1;len<=n-i;len++){
                string str = s.substr(i,len);
                if(isPalindrome(str)) cnt++;
            }
        }
        return cnt;
    }
};