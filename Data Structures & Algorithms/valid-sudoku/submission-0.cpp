class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<std::string> s;

        for (int i{}; i < 9; i++) {
            for(int j{}; j < 9; j++) {
                char val = board[i][j];
                if (val != '.') {
                    if (
                        !s.insert(std::string("r") + (char) i + val).second ||
                        !s.insert(std::string("c") + (char) j + val).second ||
                        !s.insert(std::string("m") + (char) (i / 3) + (char) (j / 3) + val).second
                    ) return false;
                }
            }
        }
        return true;
    }
};
