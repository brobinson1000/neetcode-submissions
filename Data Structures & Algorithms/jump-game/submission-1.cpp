class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int fuel{};

        for (int i{}; i < nums.size() -1; i++) {
            
            fuel = std::max(fuel, nums[i]);

            if (fuel == 0) {
                return false;
            }
            fuel--;
        }
            return true;
    }
};
