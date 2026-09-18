class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result{};

        for (const auto& s : strs) {
            result += std::to_string(s.size()) + "#" + s;
        }
        
        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        size_t i{};

        while (i < s.size()) {
            size_t j = s.find("#", i);

            int len = std::stoi(s.substr(i, j - i));

            result.push_back(s.substr(j + 1, len));

            i = j + len + 1;


        }
        return result;
    }
};
