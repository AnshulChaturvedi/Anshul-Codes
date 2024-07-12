class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string max_str = (x > y) ? "ab" : "ba";
        string min_str = (x < y) ? "ab" : "ba";
        
        stack<char> st;
        string first_pass = "";
        int ans = 0;

        //1st pass
        for(auto &ch : s){
            if(!st.empty() && ch == max_str[1] && st.top() == max_str[0]){
                st.pop();
                first_pass.pop_back();
                ans += max(x,y);
            }
            else{
                first_pass.push_back(ch);
                st.push(ch);
            }
        }

        //2nd pass
        while(!st.empty()){
            st.pop();
        }
        string second_pas = "";

        for(auto &ch : first_pass){
            if(!st.empty() && ch == min_str[1] && st.top() == min_str[0]){
                st.pop();
                second_pas.pop_back();
                ans += min(x,y);
            }
            else{
                second_pas.push_back(ch);
                st.push(ch);
            }
        }
        return ans;
    }
};