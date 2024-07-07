class Solution {
public:
    int numWaterBottles(int n, int m) {
        if(n<m) return n;
        return n + (n-1)/(m-1);
    }
};