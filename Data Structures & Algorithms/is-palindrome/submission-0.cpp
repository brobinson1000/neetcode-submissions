class Solution {
   public:
    bool isPalindrome(string s) {
        auto alphnum{
            std::remove_if(s.begin(), s.end(), [](unsigned char c) { return !std::isalnum(c); })};

        s.erase(alphnum, s.end());

        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        std::string temp{s};
        std::reverse(temp.begin(), temp.end());

        return (temp == s);
    }
};
