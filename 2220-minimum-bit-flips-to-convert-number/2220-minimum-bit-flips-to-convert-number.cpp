class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = start ^ goal;
        int count = __builtin_popcount(result);
        return count;
    }
};