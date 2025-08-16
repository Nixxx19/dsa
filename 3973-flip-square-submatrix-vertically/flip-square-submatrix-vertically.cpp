class Solution 
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int row, int col, int len) 
    {
        for (int r = 0; r < len / 2; r++) 
        {
            for (int c = 0; c < len; c++) 
            {
                swap(grid[row + r][col + c], grid[row + len - r - 1][col + c]);
            }
        }
        return grid;
    }
};
