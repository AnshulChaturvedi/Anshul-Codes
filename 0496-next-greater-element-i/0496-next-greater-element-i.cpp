class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size(), m=nums2.size();
        for(int i=0;i<n;i++){
            int val = nums1[i];
            int j=0;
            while(j<m){
                if(nums2[j] == val){
                    while(j<m && nums2[j] <= val){
                        j++;
                    }
                    if(j == m) ans.push_back(-1);
                    else{
                        ans.push_back(nums2[j]);
                        break;
                    }
                }
                j++;
            }
        }
        return ans;
    }
};