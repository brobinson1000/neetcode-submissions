use std::cmp;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut cur_max = nums[0];
        let mut max_sa = nums[0];

// skip(1) -> skips first element in iteration sequence
        for &num in nums.iter().skip(1) {
            cur_max = cmp::max(cur_max + num, num);
            max_sa = cmp::max(cur_max, max_sa);
        }

        max_sa
    }
}
