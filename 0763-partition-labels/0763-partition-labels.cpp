class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mpp;
        for(auto &c : s) mpp[c]++;

        unordered_set<char> st;
        vector<int> ans, idx;
        idx.push_back(-1);
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]--;
            st.insert(s[i]);
            if(mpp[s[i]] == 0){
                st.erase(s[i]);
                if(st.empty()){
                    idx.push_back(i);
                }
            }
        }
        for(int i=1; i<idx.size(); i++){
            int val = idx[i] - idx[i-1];
            ans.push_back(val);
        }
        return ans;
    }
};