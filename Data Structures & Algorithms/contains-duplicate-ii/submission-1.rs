impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        let mut window = HashSet::with_capacity(k);

        for i in 0..nums.len() {
            if i > k {
                window.remove(&nums[i - k - 1]);
            }

            if !window.insert(nums[i]) {
                return true
            }
        }

        false

    }
}
