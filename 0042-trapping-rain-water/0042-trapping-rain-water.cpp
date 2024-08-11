class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //for each building maxi water it can store is 
        // min{leftMax, rightMax} - height of that building
        vector<int> prefixMax(n);
        prefixMax[0] = height[0];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1],height[i]);
        }
        vector<int> suffixMax(n);
        suffixMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }
        //
        int total = 0;
        for(int i=0;i<n;i++){
            int leftMax = prefixMax[i], rightMax = suffixMax[i];
            total += min(leftMax,rightMax)-height[i];
        }
        return total;
    }
};