impl Solution {
    pub fn is_happy(mut n: i32) -> bool {
        while n != 1 && n != 4 {
            let mut total = 0;
            while n > 0 {
                let digit = n % 10;
                total += digit * digit;
                n /= 10;
            }
            n = total;
        }
        n == 1
    }
}
