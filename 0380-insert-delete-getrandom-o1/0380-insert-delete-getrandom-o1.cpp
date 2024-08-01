class RandomizedSet {
public:
    set<int> st;

    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        if(st.find(val) == st.end()){
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val) != st.end()){
            st.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randomIdx = rand() % st.size();
        auto it = next(st.begin(),randomIdx);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */