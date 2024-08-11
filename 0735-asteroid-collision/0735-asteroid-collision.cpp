class Solution {
public:
    int sign(int val){
        if(val>0) return 1;
        return -1;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto &it : asteroids){
            bool destroyed = false;
            while(!st.empty() && sign(st.top())>0 && sign(it)<0){// checking only when the they are actually colliding or not test case(129)
                if(abs(st.top()) == abs(it)){
                    st.pop();
                    destroyed = true;
                    break;
                }
                else if(abs(st.top()) < abs(it)){
                    st.pop();
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) st.push(it);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};