class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int unique{};
        
        for (const auto &num : nums ) {
            unique ^= num; // ^= XOR op
        }

        return unique;
    }
};
