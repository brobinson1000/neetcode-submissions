class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen;
        int left{};
        int max_sub{};

        for (int right{}; right < s.length(); right++) {
            
            while(seen.contains(s[right])) {
                seen.erase(s[left]);
                left++;
            }


            seen.insert(s[right]);
            max_sub = std::max(max_sub, right - left + 1);
        }
        return max_sub;
    }
};
