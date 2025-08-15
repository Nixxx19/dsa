class Solution {
public:
    string generate(string current, int step, int target) {
        if (step == target) return current;
        string result = "";
        int i = 0;
        while (i < current.length()) {
            int count = 1;
            while (i + 1 < current.length() && current[i] == current[i + 1]) {
                count++;
                i++;
            }
            result += to_string(count) + current[i];
            i++;
        }
        return generate(result, step + 1, target);
    }

    string countAndSay(int n) {
        return generate("1", 1, n);
    }
};
