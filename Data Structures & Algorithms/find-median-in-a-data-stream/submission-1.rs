struct MedianFinder {
    nums: Vec<i32>,
}

impl MedianFinder {
    pub fn new() -> Self {
        MedianFinder{
            nums: vec![]
        }
    }

    pub fn add_num(&mut self, num: i32) {
        self.nums.push(num);
        self.nums.sort_unstable();
    }

    pub fn find_median(&self) -> f64 {
        let s = self.nums.len();

        if s == 0 {
            return 0.0;
        }

        if s % 2 == 0 {
            let m1 = s / 2;
            let m2 = (s / 2 ) - 1;
            return (self.nums[m1] + self.nums[m2]) as f64 / 2.0;
        }

        self.nums[s / 2] as f64

    }
}
