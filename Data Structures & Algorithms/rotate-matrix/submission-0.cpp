class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t ms{matrix.size()};

        // transpose matrix
        // int j = i + 1; because we do not want to swap element 2 times
        for (int i{}; i < ms; i++) {
            for (int j{i + 1}; j < ms; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            } 
        }

        // reverse each row
        for (int i{}; i < ms; i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};
