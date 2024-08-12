class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //take each bar and find the maximum area it can form using that bar as mini ht
        vector<int> nse(n),pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int ht = heights[i];
            int wt = nse[i]-pse[i]-1;
            ans = max(ans,ht*wt);
        }
        return ans;
    }
};