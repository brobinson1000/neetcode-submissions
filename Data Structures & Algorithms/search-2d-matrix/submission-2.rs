impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.is_empty() || matrix[0].is_empty() {
            return false;
        }

        let n = matrix.len();
        let m = matrix[0].len();

        let mut low = 0;
        let mut high = (m * n ) - 1;

        while low <= high {
            let mid = low + (high - low) / 2;
            let mid_val = matrix[mid / m][mid % m];

            if target == mid_val {
                return true;
            } else if target > mid_val {
                low = mid + 1;
            } else {

                if mid == 0 {
                    break;
                }

                high = mid - 1;
            }
        }
        false

    }
}
