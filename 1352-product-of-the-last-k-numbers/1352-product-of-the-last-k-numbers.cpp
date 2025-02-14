class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {
        vec.empty();
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        int n = vec.size();
        int prod = 1;
        while(k--){
            prod *= vec[n-k-1];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */