class Solution {
public:
    bool isHappy(int n) {
        while(n != 1 && n != 4) {
            int total{};
            while(n > 0) {
                int digit = n % 10;
                total += digit * digit;
                n /= 10;
            }
            n = total;
        }
        return n == 1;
    }
};
