class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int> final_arr = nums;
        for(int i = 0;i < nums.size();i++)
        {
            final_arr.push_back(nums[i]);
        }
        return final_arr;
    }
};