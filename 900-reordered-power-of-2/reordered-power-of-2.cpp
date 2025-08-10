class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = sortDigits(n);

        for(int i = 0; i<30; i++){
            int power = 1 << i;
            if(s == sortDigits(power)){
                return true;
            }
        }
        return false;
    }


           string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};