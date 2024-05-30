class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int xorSum = 0;
            for(int j=i;j<n;j++){
                xorSum ^= arr[j];
                if(xorSum == 0){
                    cnt += (j-i);
                }
            }
        }
        return cnt;
    }
};