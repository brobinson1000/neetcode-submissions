impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {

        if prices.is_empty() {
            return 0;
        }

        let mut hold : i32 = -prices[0];
        let mut sold : i32 = 0;
        let mut rest : i32 = 0;

        for (i, &price ) in prices.iter().enumerate().skip(1) {
            let mut prev_hold = hold;
            let mut prev_sold = sold;
            let mut prev_rest = rest;

            hold = prev_hold.max(prev_rest - prices[i]);
            sold = prev_hold + prices[i];
            rest = prev_sold.max(prev_rest);
        }
        sold.max(rest)
    }
}
