class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> mergedArray;

        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else{
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            mergedArray.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            mergedArray.push_back(nums2[j]);
            j++;
        }

        int size = mergedArray.size();
        if(size&1){
            return mergedArray[size/2];
        }
        return (mergedArray[size/2] + mergedArray[size/2 - 1])/2.0;

    }
};