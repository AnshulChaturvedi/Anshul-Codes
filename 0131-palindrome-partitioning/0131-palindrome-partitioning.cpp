class Solution {
private:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(int index,vector<vector<string>> &ans,vector<string> result,string s,int n){
        if(index == n){
            ans.push_back(result);
            return;
        }

        for(int i=index;i<n;i++){
            if(isPalindrome(s,index,i)){
                result.push_back(s.substr(index,i-index+1));
                solve(i+1,ans,result,s,n);
                result.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> result;
        solve(0,ans,result,s,n);
        return ans;
    }
};