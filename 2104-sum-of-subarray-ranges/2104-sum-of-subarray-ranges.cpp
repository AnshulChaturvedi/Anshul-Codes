class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        //**********//
        vector<int> leftMax(n),rightMax(n),leftMin(n),rightMin(n);
        //for left and right min
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            leftMin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            rightMin[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        //for left and right max
        st = stack<int>();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            leftMax[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            rightMax[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        //***********//
        long long ans = 0;
        for(int i=0;i<n;i++){
            int maxContribution = (i-leftMax[i])*(rightMax[i]-i);
            int minContribution = (i-leftMin[i])*(rightMin[i]-i);
            ans += (long long)nums[i]*(maxContribution-minContribution);
        }
        return ans;
    }
};