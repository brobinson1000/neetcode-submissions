class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        std::vector<vector<int>> pNums;
        
        std::sort(nums.begin(), nums.end());

        do {
            pNums.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return pNums;
    }
};
