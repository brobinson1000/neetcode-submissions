class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_max = nums[0];
        int max_sa = nums[0];

        for (int i{1}; i < nums.size(); i++) {
            cur_max = std::max(nums[i], nums[i] + cur_max);
            max_sa = std::max(cur_max, max_sa);
        }

        return max_sa;
    }
};
