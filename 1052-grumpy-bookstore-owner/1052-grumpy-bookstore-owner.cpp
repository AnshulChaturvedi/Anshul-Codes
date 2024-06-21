class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();

        int totalCust = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0)
                totalCust += customers[i];
        }

        int maxSum = 0, currSum = 0;

        for(int i=0;i<minutes;i++){ // calculating for first window
            if(grumpy[i] == 1){
                currSum += customers[i];
            }
        }
        maxSum = currSum;

        for(int i=minutes;i<n;i++){ // for all windows
            if(grumpy[i] == 1){
                currSum += customers[i];
            }
            if(grumpy[i-minutes] == 1){
                currSum -= customers[i-minutes];
            }
            maxSum = max(maxSum, currSum);
        }
        
        return totalCust + maxSum;
    }
};