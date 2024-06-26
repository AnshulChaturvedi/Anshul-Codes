class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(auto &i : arr1){
            bool found = false;
            for(auto &j : arr2){
                if(abs(i-j) <= d){
                    found = true;
                    break;
                }
            }
            if(found == false) cnt++;
        }
        return cnt;
    }
};