struct Node{
    Node* list[26];
    bool flag = false;

    bool containsKey(char ch){
        return list[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        list[ch-'a'] = node;
    }
    Node* get(char ch){
        return list[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
    bool searchHelper(string &word, int idx){
        if(idx == word.size()) return flag;
        char ch = word[idx];
        if(ch != '.'){
            if(!containsKey(ch)){
                return false;
            }
            return get(ch)->searchHelper(word, idx+1);
        }
        for(int i=0; i<26; i++){
            if(list[i] != NULL && list[i]->searchHelper(word,idx+1))
                return true;
        }
        return false;
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return root->searchHelper(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */