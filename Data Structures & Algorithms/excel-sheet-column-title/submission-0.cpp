class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        std::string res{};

        while (columnNumber > 0) {
            columnNumber--;

            char c = 'A' + (columnNumber % 26);

            res += c;

            columnNumber /= 26;
        }

        std::reverse(res.begin(), res.end());
        return res;


    }
};