impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut seen = HashSet::new();

        for item in nums {
            if !seen.insert(item) {
                return true;
            }
        }
        false
    }
}
