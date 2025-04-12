#define ll long long

class Solution {
public:
    int n;
    vector<ll> fact;
    unordered_set<ll> st;

    // void generateNum(string curr, int n, vector<ll> &vec){
    //     if(curr.length() == n){
    //         ll val = stoll(curr);
    //         vec.push_back(val);
    //         return;
    //     }

    //     char start = curr.empty() ? '1' : '0';

    //     for(char digit = start; digit <= '9'; digit++){
    //         generateNum(curr + digit, n, vec);
    //     }
    // }
    
    void generateAllPalindrome(const string &curr, int n, vector<ll> &vec){
        int halfLen = (n+1)/2;
        if(curr.length() == halfLen){
            string pal = curr;
            int mirror = (n % 2 == 1) ? curr.size() - 2 : curr.size() - 1;
            for(int i = mirror; i>=0; i--){
                pal.push_back(curr[i]);
            }
            vec.push_back(stoll(pal));
            return;
        }
        for(char d = '0'; d <= '9'; d++){
            if(curr.empty() && d == '0') continue;
            generateAllPalindrome(curr + d, n, vec);
        }
    }

    void generateFact(int &n){
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2; i<=10; i++){
            fact[i] = i*fact[i-1];
        }
    }

    // bool isPalindrome(ll &num){
    //     string s = to_string(num);
    //     int i=0, j=s.length()-1;
    //     while(i<j){
    //         if(s[i++] != s[j--]) return false;
    //     }
    //     return true;
    // }

    ll countArrangements(vector<ll> &freq, int n){
        ll cnt = fact[n];
        for(int i=0; i<=9; i++){
            cnt /= fact[freq[i]];
        }
        return cnt;
    }

    ll numOfPerm(ll &num){
        string s = to_string(num);
        sort(s.begin(), s.end());
        if(st.count(stoll(s))){
            return 0;
        }
        st.insert(stoll(s));

        vector<ll> freq(10);
        for(auto ch : s){
            freq[ch-'0']++;
        }
        ll totalArrangements = countArrangements(freq, n);
        ll invalidArrangements = 0;
        if(freq[0] > 0){
            freq[0]--;
            invalidArrangements = countArrangements(freq, n-1);
        }
        return totalArrangements - invalidArrangements;
    }

    long long countGoodIntegers(int m, int k) {
        n = m;
        fact = vector<ll>(11);
        generateFact(n);
        ll cnt = 0;
        vector<ll> vec;
        generateAllPalindrome("", n, vec);
        for(int i=0; i<vec.size(); i++){
            if(vec[i] % k == 0){
                cnt += numOfPerm(vec[i]);
            }
        }
        return cnt;
    }
};