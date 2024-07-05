class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            for(int k=0;k<size;k++){
                string s = q.front();
                q.pop();
                if(s == endWord) return steps;
                int n = s.length();
                for(int i=0;i<n;i++){
                    char temp = s[i];
                    for(char c='a';c<='z';c++){
                        s[i] = c;
                        if(st.find(s) != st.end()){
                            q.push(s);
                            st.erase(s);
                        }
                    }
                    s[i] = temp;
                }
            }
            steps++;
        }
        return 0;
    }
};