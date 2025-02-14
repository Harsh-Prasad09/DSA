class ProductOfNumbers {
private:
    vector<int> product;
    int n;
public:
    ProductOfNumbers() {
        product.clear();
        n = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            product.clear();
            n = 0;
            return;
        }
        if (n == 0) product.push_back(num);
        else product.push_back(product.back()*num);
        n++;
    }
    
    int getProduct(int k) {
        if (k > n) return 0;

        if (k == n) return product.back();
        return product.back()/product[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
