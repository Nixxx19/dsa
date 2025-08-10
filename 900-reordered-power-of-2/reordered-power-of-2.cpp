class Solution {
public:
    string getSortedDigits(int num) 
    {
        string digits = to_string(num);
        sort(digits.begin(), digits.end());
        return digits;
    }

    bool reorderedPowerOf2(int n) 
    {
        string targetDigits = getSortedDigits(n);

        for (int i = 0; i < 30; ++i) 
        {
            int powerOfTwo = 1 << i;
            string powerDigits = getSortedDigits(powerOfTwo);

            if (powerDigits == targetDigits)
                return true;
        }

        return false;
    }
};
