class Solution {
public:
    int areaOfHisto(vector<int> &heights,int n){
        int ans = 0;
        int tp,area;
        int i=0;
        stack<int> st;
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]-'0' == 0){
                    heights[j] = 0;
                }
                else{
                    heights[j] += matrix[i][j]-'0';
                }
            }
            ans = max(ans,areaOfHisto(heights,n));
        }
        return ans;
    }
};