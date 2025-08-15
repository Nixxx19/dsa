class Solution {
public:
    bool isPowerOfFour(int n) {
        bitset<40> bits(n);
        if(n<0) return false;
        if(n==1) return true;
        string binary = bits.to_string();
        int index = -1;
        //for(auto it: binary) cout << it;
        for(int i =0;i<40;i++){
            if(binary[i]=='1'){
                index = i;
                break;
            };
        }
        if(index == -1) return false;
        //cout << index;
        if(index%2 == 0) return false;
        
        for(int i = index+1;i<40;i++){
            if(binary[i]=='1') return false;
        }
        return true;

    }
};