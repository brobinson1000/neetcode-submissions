class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        auto it = std::adjacent_find(nums.begin(), nums.end());

        if (it != nums.end()) {
            return true;
        } else {
            return false;
        }
    }
};