class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        // 26 letter alphabet spaces
        int counts[26] = {0};

        // anytime we see a letter in s we add 1 and if we see in t we - 1
        for (int i{}; i < s.length(); i++) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }

        // if an anagram count should only contain 0's
        for (const auto& count : counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
