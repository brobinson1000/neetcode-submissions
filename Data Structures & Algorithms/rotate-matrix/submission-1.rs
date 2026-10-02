impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let ms = matrix.len();

        for i in 0..ms {
            for j in (i + 1)..ms {
                let temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for i in 0..ms {
            matrix[i].reverse();
        }
    }
}
