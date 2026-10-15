impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut expected: usize = 0;

        for i in 0..nums.len() {
            if nums[i] != 0 {
                nums.swap(i, expected);
                expected += 1;
            }
        }

    }
}
