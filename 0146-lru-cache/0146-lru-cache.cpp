class LRUCache {
public:
    list<int> dll;
    map<int,pair<list<int>::iterator,int>> mpp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecent(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
        return;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;
        makeRecent(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            makeRecent(key);
            mpp[key].second = value;
        }
        else{
            dll.push_front(key);
            mpp[key].first = dll.begin();
            mpp[key].second = value;
            n--;
        }
        if(n<0){
            mpp.erase(dll.back());
            dll.pop_back();
            n++;
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */