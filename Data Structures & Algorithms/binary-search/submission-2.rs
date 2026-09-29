impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        if nums.len() == 0 {
            return -1;
        }

        let mut left : usize = 0;
        let mut right : usize = nums.len() -1;

        while left <= right {
            let mut mid : usize = left + (right - left) / 2;

            if nums[mid] == target {
                return mid as i32;
            } else if nums[mid] < target {
                left = mid + 1;
            } else {
                if mid == 0 {
                    break;
                }
                right = mid - 1;
            }
        }
        -1

    }
}
