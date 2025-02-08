class NumberContainers {
public:
    unordered_map<int,int> mpp1;
               // Index, Number
    map<int,set<int>> mpp2;
               // Number, Smallest Index
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mpp1.find(index) != mpp1.end()){
            int num = mpp1[index];
            mpp2[num].erase(index);
        }
        mpp1[index] = number;
        mpp2[number].insert(index);
    }
    
    int find(int number) {
        if(mpp2.find(number) != mpp2.end()){
            int val = *mpp2[number].begin();
            return (val == 0) ? -1 : val;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */