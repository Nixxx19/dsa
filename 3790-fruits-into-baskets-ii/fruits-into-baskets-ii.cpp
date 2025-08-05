class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        vector<bool> u(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!u[j] && b[j] >= f[i]) {
                    u[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) cnt++;
        }
        return cnt;
    }
};
