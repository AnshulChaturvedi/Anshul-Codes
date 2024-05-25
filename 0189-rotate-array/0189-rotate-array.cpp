class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> store;
        int i = nums.size()-1;
        k = k % nums.size();
        while(k--){
            store.push_back(nums[i]);
            i--;
        }
        int n = store.size();
        for(int j=nums.size()-1;j>=n;j--){
            nums[j] = nums[j-n];
        }
        reverse(store.begin(),store.end());
        for(int l=0;l<n;l++){
            nums[l] = store[l];
        }
    }
};