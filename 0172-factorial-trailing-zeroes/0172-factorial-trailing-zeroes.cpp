class Solution {
public:
    int trailingZeroes(int n) {
        // long long val = 1;
        // for(long long i=1; i<=n; i++){
        //     val = val * i;
        // }
        // string s = to_string(val);
        // long long size = s.size();
        // long long cnt = 0;
        // for(long long i=size-1; i >=0 ; i--){
        //     if(s[i] == '0'){
        //         cnt++;
        //     }
        //     else break;
        // }
        // return cnt;
        int cnt = 0;
        for(int i=5; (n/i)>0; i*=5){
            cnt += (n/i);
        }
        return cnt;
    }
};