class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int first{1};
        int second{2};
        int next{};

        for (int i = 3; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
        }

        return next;

    }
};
