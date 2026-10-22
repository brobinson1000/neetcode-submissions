class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit{};

        for (const auto& price : prices) {
            if (price < min_price) {
                min_price = price;
            } else {
                max_profit = std::max(price - min_price, max_profit);
            }
        }
        return max_profit;
    }
};
