class Solution {
public:
    string solve(string s, int count, int n) {
        if (count == n) return s;
        string next = "";
        for (int i = 0; i < s.size(); i++) {
            int len = 1;
            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                len++;
                i++;
            }
            next += to_string(len) + string(1, s[i]);
        }
        return solve(next, count + 1, n);
    }

    string countAndSay(int n) {
        return solve("1", 1, n);
    }
};
