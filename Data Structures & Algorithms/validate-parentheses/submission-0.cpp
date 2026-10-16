class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for (const auto &c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                
                if (stk.empty()) return false;

                char top = stk.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')
                ) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
