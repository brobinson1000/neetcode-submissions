class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int prev2{}; // 2 houses ago
        int prev1{}; // 1 house ago

        for (const auto& n : nums) {
            int current = std::max(prev1, prev2 + n);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
