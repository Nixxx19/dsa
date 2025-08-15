class Solution 
{
public:
    bool isPowerOfFour(int number) 
    {
        if (number < 1) return false;
        string bits = bitset<40>(number).to_string();
        int position = -1;
        for (int i = 0; i < 40; i++) 
        {
            if (bits[i] == '1') 
            {
                position = i;
                break;
            }
        }
        if (position == -1 || position % 2 == 0) return false;
        for (int i = position + 1; i < 40; i++) 
        {
            if (bits[i] == '1') return false;
        }
        return true;
    }
};
