class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = 0;
        int i=0, j=n-1;
        while(i < j){
            int water = min(height[i],height[j])*(j-i);
            maxi = max(maxi, water);
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return maxi;
    }
};