class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expSum{static_cast<int>((nums.size() * (nums.size() + 1) / 2))};
        int actSum{};

        for (const auto& num : nums) {
            actSum += num;
        }

        return expSum - actSum;
    }
};
