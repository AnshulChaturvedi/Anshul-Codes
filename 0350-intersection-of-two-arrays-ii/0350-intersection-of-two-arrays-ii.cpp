class Solution {
public:
    vector<int> arr;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        arr.resize(1000+1);

        if(n>m){
            for(int i=0;i<n;i++){
                arr[nums1[i]]++;
            }
            for(auto &num : nums2){
                if(arr[num] != 0){
                    ans.push_back(num);
                    arr[num]--;
                }
            }
        }
        else{
            for(int i=0;i<m;i++){
                arr[nums2[i]]++;
            }
            for(auto &num : nums1){
                if(arr[num] != 0){
                    ans.push_back(num);
                    arr[num]--;
                }
            }
        }
        return ans;
    }
};