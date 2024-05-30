class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                result.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]){
                result.push_back(nums2[j]);
                j++;
            }
            else{
                result.push_back(nums1[i]);
                i++;
            }
        }
        while(i<m){
            result.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            result.push_back(nums2[j]);
            j++;
        }
        
        for(int i=0;i<result.size();i++){
            nums1[i] = result[i];
        }

    }
};