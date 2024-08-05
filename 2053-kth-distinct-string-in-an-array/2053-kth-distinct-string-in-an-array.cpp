class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        for(auto it : arr){
            mpp[it]++;
        }
        int cnt = 0;
        for(auto &it : arr){
            if(mpp[it] == 1){
                cnt++;
                if(cnt == k) return it;
            }
        }
        return "";
    }
};