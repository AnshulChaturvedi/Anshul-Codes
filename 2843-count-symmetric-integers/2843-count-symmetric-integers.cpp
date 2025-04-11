class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        if((low >= 1 && high <= 9) || (low >= 100 && high <= 999)) return 0;
        int cnt = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            if(s.length()&1) continue;

            int total = 0, half = 0;
            
            for(auto ch : s){
                total += (ch-'0');
            }
            for(int j = 0; j < s.size()/2; j++){
                half += (s[j]-'0');
            }
            if(total == 2 * half) cnt++;
        }
        return cnt;
    }
};