class Solution {
public:
    const int M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        //***********//
        vector<int> pseLeft(n),nseRight(n);
        stack<int> st1,st2;
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[st1.top()] > arr[i]){
                st1.pop();
            }
            pseLeft[i] = (st1.empty()) ? -1 : st1.top();
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()] >= arr[i]){
                st2.pop();
            }
            nseRight[i] = (st2.empty()) ? n : st2.top();
            st2.push(i);
        }
        //*********//
        long long ans = 0;
        for(int i=0;i<n;i++){
            int left = i-pseLeft[i];
            int right = nseRight[i]-i;
            long long contribution = (long long)left*right*arr[i]%M;
            ans = (ans + contribution)%M;
        }
        return (int)ans;
    }
};