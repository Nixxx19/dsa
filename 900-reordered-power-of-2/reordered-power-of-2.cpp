class Solution {
public:
    bool isPowerOfTwo(int num) {
        return num > 0 && (num & (num - 1)) == 0;
    }

    bool backtrack(string& digits, vector<bool>& used, string& current) {
        if (current.size() == digits.size()) {
            if (current[0] == '0') return false; 
            int number = stoi(current);
            return isPowerOfTwo(number);
        }

        for (int i = 0; i < digits.size(); ++i) {
            if (used[i]) continue;

            used[i] = true;
            current.push_back(digits[i]);

            if (backtrack(digits, used, current)) return true;

            current.pop_back();
            used[i] = false;
        }

        return false;
    }

    bool reorderedPowerOf2(int n) {
        string digits = to_string(n);
        vector<bool> used(digits.size(), false);
        string current;

        return backtrack(digits, used, current);
    }
};
