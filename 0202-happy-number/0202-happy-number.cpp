class Solution {
public:
    int sum_of_squares(int n){
        int res = 0;
        while(n){
            int last_digit = n % 10;
            res += (last_digit)*(last_digit);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int val = sum_of_squares(n);
        int slow = n, fast = val;
        while(slow != fast){
            slow = sum_of_squares(slow);
            fast = sum_of_squares(sum_of_squares(fast));
        }
        return slow==1;
    }
};