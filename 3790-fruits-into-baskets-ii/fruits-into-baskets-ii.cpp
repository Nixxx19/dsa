class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        list<int> available;  \
        for (int i = 0; i < n; i++) available.push_back(i);

        int unplaced = 0;
        for (int fruit : f) {
            bool placed = false;
            for (auto it = available.begin(); it != available.end(); ++it) {
                if (b[*it] >= fruit) {
                    available.erase(it); 
                    placed = true;
                    break;
                }
            }
            if (!placed) unplaced++;
        }
        return unplaced;
    }
};
