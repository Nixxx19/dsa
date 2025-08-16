class Solution 
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int startRow, int startCol, int size) 
    {
        for (int rowOffset = 0; rowOffset < size / 2; rowOffset++) 
        {
            for (int colOffset = 0; colOffset < size; colOffset++) 
            {
                swap(grid[startRow + rowOffset][startCol + colOffset], 
                     grid[startRow + size - rowOffset - 1][startCol + colOffset]);
            }
        }
        return grid;
    }
};
