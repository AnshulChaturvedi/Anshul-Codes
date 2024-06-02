class Solution {
public:
    void reverseString(vector<char>& st) {
        int n = st.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            swap(st[s++],st[e--]);
        }
    }
};