class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        int original = x;
        long long reversed_no = 0;

        while (x > 0)
        {
            reversed_no = reversed_no * 10 + x % 10;
            x /= 10;
        }

        return reversed_no == original;
    }
};
