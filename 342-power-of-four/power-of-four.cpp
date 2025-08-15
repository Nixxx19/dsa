class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        string bin = bitset<40>(n).to_string();
        int pos = -1;
        for (int i = 0; i < bin.size(); i++) {
            if (bin[i] == '1') {
                pos = i;
                break;
            }
        }
        if (pos == -1 || pos % 2 == 0) return false;
        for (int j = pos + 1; j < bin.size(); j++) {
            if (bin[j] == '1') return false;
        }
        return true;
    }
};
