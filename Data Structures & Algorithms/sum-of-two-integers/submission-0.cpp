class Solution {
public:
    int getSum(int a, int b) {
        
        while(b != 0) {
            int carry{a & b}; // find carry

            a = a ^ b; // simulate addition

            b = carry << 1; // shift each binary digits 1 to the left

        }

        return a;

    }
};
