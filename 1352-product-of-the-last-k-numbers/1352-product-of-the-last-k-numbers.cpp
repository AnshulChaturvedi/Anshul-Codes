class ProductOfNumbers {
public:
    vector<int> preMult;
    ProductOfNumbers() {
        preMult.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            preMult.clear();
            preMult.push_back(1);
        }
        else preMult.push_back(preMult.back()*num);
    }
    
    int getProduct(int k) {
        int n = preMult.size();
        if(k >= n) return 0;
        return preMult[n-1]/preMult[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */