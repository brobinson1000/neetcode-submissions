class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t expected{};

        for (int i{}; i < nums.size(); i++) {
            if (nums[i] != 0) {
                std::swap(nums[i], nums[expected]);
                expected++;
            }
        }
    }
};