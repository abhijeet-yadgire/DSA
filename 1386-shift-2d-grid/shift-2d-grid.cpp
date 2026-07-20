class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
int rows = grid.size();
        int cols = grid[0].size();
        int totalElements = rows * cols;

        vector<int> plain_Grid;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                plain_Grid.push_back(grid[i][j]);
            }
        }

        vector<int> shifted(totalElements);
        for (int i = 0; i < totalElements; i++) {
            int newIndex = (i + k) % totalElements;
            shifted[newIndex] = plain_Grid[i];
        }

        vector<vector<int>> ans(rows, vector<int>(cols));

        int t = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans[i][j] = shifted[t];
                t++;
            }
        }

        return ans;
    }
};