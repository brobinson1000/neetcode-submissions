class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> window;

        for (int i{}; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }

            if (!window.insert(nums[i]).second) {
                return true;
            }
        }

        return false;
    }
};