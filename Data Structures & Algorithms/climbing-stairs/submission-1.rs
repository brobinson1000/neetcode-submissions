impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 {
            return n;
        }

        let mut first = 1;
        let mut second = 2;
        let mut next = 0;

        for _ in 3..=n {
            next = first + second;
            first = second;
            second = next;
        }

        next
    }
}
