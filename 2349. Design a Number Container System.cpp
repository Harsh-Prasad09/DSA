class NumberContainers {
private:
    unordered_map<int, int> indices;
    unordered_map<int, set<int>> numbers;
public:
    NumberContainers() {
        indices.clear();
        numbers.clear();
    }
    
    void change(int index, int number) {
        if (indices.find(index) != indices.end()){
            numbers[indices[index]].erase(index);
        }
        indices[index] = number;
        numbers[number].insert(index);
    }
    
    int find(int number) {
        if (numbers[number].size() == 0) return -1;
        return *numbers[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
