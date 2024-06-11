class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }

        int i=0, sign = 1, result = 0;
        //step 1;
        while(i<n && s[i] == ' '){
            i++;
        }
        //step 2;
        if(i<n && s[i] == '+'){
            sign = 1;
            i++;
        }
        else if(i<n && s[i] == '-'){
            sign = -1;
            i++;
        }
        //step 3;
        while(i<n && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return result*sign;
    }
};