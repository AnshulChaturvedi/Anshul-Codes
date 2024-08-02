class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        int tp,area;
        int i=0;
        while(i<n){
            if(st.empty() || heights[i] >= heights[st.top()]){
                st.push(i++);
            }
            else{
                tp = st.top();
                st.pop();
                area = heights[tp]*(st.empty() ? i : i-st.top()-1);
                ans = max(ans,area);
            }
        }
        while(!st.empty()){
            tp = st.top();
            st.pop();
            area = heights[tp]*(st.empty() ? i : i-st.top()-1);
            ans = max(ans,area);
        }
        return ans;
    }
};