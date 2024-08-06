class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = nums[i]&nums[j];
                mpp[val]++;
            }
        }
        for(int k=0;k<n;k++){
            for(auto &it : mpp){
                if((nums[k]&(it.first)) == 0){
                    cnt += it.second;
                }
            }
        }
        return cnt;
    }
};