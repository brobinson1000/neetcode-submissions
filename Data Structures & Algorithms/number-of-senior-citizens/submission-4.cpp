class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (const auto& s : details) {
            // Force strict parentheses grouping to protect operator priority
            if ((s[11] > '6') || (s[11] == '6' && s[12] > '0')) {
                count++;
            }
        }
        return count;
    }
};
