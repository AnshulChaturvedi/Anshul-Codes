class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;

        int n = A.size();
        int cnt = 0;
        unordered_set<int> setA, setB;

        for(int i=0; i<n; i++){
            setA.insert(A[i]);
            setB.insert(B[i]);
            if(setA.find(B[i]) != setA.end()) cnt++;
            if(setB.find(A[i]) != setB.end()) cnt++;
            if(A[i] == B[i]) cnt--;
            ans.push_back(cnt);
        }
        return ans;
    }
};