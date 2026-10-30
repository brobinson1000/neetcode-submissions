impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut unique = 0;

        for num in nums {
            unique ^= num;
        }

        unique
    }
}
