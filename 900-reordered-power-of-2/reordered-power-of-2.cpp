class Solution {
public:
    bool isPowerOfTwo(int number) 
    {
        return number > 0 && (number & (number - 1)) == 0;
    }

    bool tryAllPermutations(string& inputDigits, vector<bool>& isUsed, string& currentNumber) 
    {
        if (currentNumber.size() == inputDigits.size()) 
        {
            if (currentNumber[0] == '0') return false; 
            int num = stoi(currentNumber);
            return isPowerOfTwo(num);
        }

        for (int i = 0; i < inputDigits.size(); ++i)
        {
            if (isUsed[i]) continue;

            if (i > 0 && inputDigits[i] == inputDigits[i - 1] && !isUsed[i - 1]) continue;

            isUsed[i] = true;
            currentNumber.push_back(inputDigits[i]);

            if (tryAllPermutations(inputDigits, isUsed, currentNumber)) return true;

            currentNumber.pop_back();
            isUsed[i] = false;
        }

        return false;
    }

    bool reorderedPowerOf2(int n) 
    {
        string digits = to_string(n);
        sort(digits.begin(), digits.end()); 

        vector<bool> used(digits.size(), false);
        string builtNumber = "";

        return tryAllPermutations(digits, used, builtNumber);
    }
};
