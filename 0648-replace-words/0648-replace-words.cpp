class Solution {
private:
    string findRoot(string &word, unordered_set<string> &st){
        for(int i=1;i<word.length();i++){
            string root = word.substr(0,i);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // 1:- Traverse through the sentence
        // 2:- check the all substrings of a word in a dictionary

        unordered_set<string> st(dictionary.begin(),dictionary.end());

        stringstream ss(sentence);
        string word;

        string result;
        while(getline(ss, word, ' ')){
            result += findRoot(word,st) + " ";
        }
        result.pop_back();
        return result;
    }
};