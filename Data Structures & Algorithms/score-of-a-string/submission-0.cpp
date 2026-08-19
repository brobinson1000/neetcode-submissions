class Solution {
public:
    int total{};

    int scoreOfString(string s) {
        for (int i{}; i + 1 < s.length(); ++i) {
            total += std::abs(s[i] - s[i + 1]);
        }

        return total;
    }
};