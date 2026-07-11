class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1) {

            std::sort(stones.begin(), stones.end());

            int y{stones.back()}; // heaviest stone
            stones.pop_back();

            int x{stones.back()}; // second heaviest stone
            stones.pop_back();

            if (x != y) {
                stones.push_back(y - x); // since they are sorted we can just check if !=
            }

        }

        return stones.empty() ? 0 : stones[0];
    }
};
