class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int mergeSize = n + m;
        int index2 = mergeSize/2;
        int index1 = index2 - 1;
        int cnt = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;   
        int i=0,j=0;

        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                if(cnt == index1) ele1 = nums1[i];
                if(cnt == index2) ele2 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == index1) ele1 = nums2[j];
                if(cnt == index2) ele2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n){
           if(cnt == index1) ele1 = nums1[i];
           if(cnt == index2) ele2 = nums1[i];
           cnt++;
           i++;
        }
        while(j<m){
            if(cnt == index1) ele1 = nums2[j];
            if(cnt == index2) ele2 = nums2[j];
            cnt++;
            j++;
        }

        if(mergeSize&1){
            return ele2;
        }
        return (double)(ele1 + ele2)/2.0;

    }
};