class Solution {
public:
    int findWinner(int n,int k){
        if(n == 1) return 0;
        int idx = findWinner(n-1,k);
        idx = (idx + k) % n;
        return idx;
    }

    int findTheWinner(int n, int k) {
        int res_index = findWinner(n,k);
        return res_index + 1;
    }
};