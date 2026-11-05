

impl Solution {
    pub fn predict_party_victory(senate: String) -> String {
        let n = senate.len();
        let senate_bytes = senate.as_bytes();
        let mut q_r :VecDeque<usize> = VecDeque::new();
        let mut q_d :VecDeque<usize> = VecDeque::new();

        for i in 0..n {
            if senate_bytes[i] == b'R' {
                q_r.push_back(i);
            } else {
                q_d.push_back(i);
            }
        }

        while !q_r.is_empty() && !q_d.is_empty() {
            let mut idxr = q_r.pop_front().unwrap();
            let mut idxd = q_d.pop_front().unwrap();

            if idxr < idxd {
                q_r.push_back(idxr + n);
            } else {
                q_d.push_back(idxd + n);
            }
        }

        if q_r.is_empty() {
            String::from("Dire")
        } else {
            String::from("Radiant")
        }


    }
}
