class Solution {
public:
    bool isPalindrome(int x) {

        if ( x < 0 || x % 10 == 0 && x != 0 ) {
            return false;
        }

        int reversed_half{};

        while (x > reversed_half) {
            reversed_half = (reversed_half * 10) + (x % 10);
            x /= 10;
        }

        return reversed_half == x || x == (reversed_half / 10);
        
    }
};