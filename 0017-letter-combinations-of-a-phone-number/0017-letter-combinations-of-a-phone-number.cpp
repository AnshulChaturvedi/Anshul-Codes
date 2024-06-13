class Solution {
private:
    void solve(int i,vector<string> &ans,string result,string mapping[],string digits){
        if(i == digits.size()){
            ans.push_back(result);
            return;
        }
        int num = digits[i] - '0';
        string val = mapping[num];
        for(int j=0;j<val.size();j++){
            result.push_back(val[j]);
            solve(i+1,ans,result,mapping,digits);
            result.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string result;
        if(digits.size()==0) return ans;
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,ans,result,mapping,digits);
        return ans;
    }
};