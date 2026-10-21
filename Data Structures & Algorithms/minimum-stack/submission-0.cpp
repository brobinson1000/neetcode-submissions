class MinStack {
private:
    std::vector<std::pair<int, int>> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (min_stack.empty()) {
            min_stack.push_back({val, val});
        } else {
            int current_min = std::min(val, min_stack.back().second);
            min_stack.push_back({val, current_min});
        }
    }
    
    void pop() {
        if (!min_stack.empty()) {
            min_stack.pop_back();
        }
    }
    
    int top() {
        if (!min_stack.empty()) {
            return min_stack.back().first;
        }
    }
    
    int getMin() {
        if (!min_stack.empty()) {
            return min_stack.back().second;
        }
    }
};
