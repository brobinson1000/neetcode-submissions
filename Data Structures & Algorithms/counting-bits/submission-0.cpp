class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> numOfOnes;
        numOfOnes.reserve(n + 1);

        for (int i{}; i <= n; i++) {
            numOfOnes.push_back(__builtin_popcount(static_cast<unsigned int>(i)));
        }
        
        return numOfOnes;
    }
};
