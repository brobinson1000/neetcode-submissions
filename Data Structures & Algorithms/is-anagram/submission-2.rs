impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut s1 : Vec<char> = s.chars().collect();
        let mut s2 : Vec<char> = t.chars().collect();

        s1.sort_unstable();
        s2.sort_unstable();

        s1 == s2


    }
}
