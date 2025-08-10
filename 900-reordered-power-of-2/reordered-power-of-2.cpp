class Solution {
public:
    // Returns the sorted digit signature of a number
    string getSortedDigits(int num) {
        string digits = to_string(num);
        sort(digits.begin(), digits.end());
        return digits;
    }

    bool reorderedPowerOf2(int n) {
        string targetDigits = getSortedDigits(n);

        // Loop through powers of 2 from 2^0 to 2^29 (since 2^30 > 1e9)
        for (int i = 0; i < 30; ++i) {
            int powerOfTwo = 1 << i;
            if (getSortedDigits(powerOfTwo) == targetDigits)
                return true;
        }

        return false;
    }
};
