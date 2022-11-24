class Solution {
public:

    // direction co-ordinates of all four directions

    vector<int> dx = {-1, 0, 1, 0};

    vector<int> dy = {0, 1, 0, -1};


    bool dfs(vector<vector<char>>& grid, int i, int j, int n, int m, string& word, int pos)
    {
        // base case

        if(pos >= word.size())
        {
            return true;
        }

        // if we are out of grid or cell is already visited

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#')
        {
            return false;
        }

        // if val at curr cell doesn't match with char of word

        if(grid[i][j] != word[pos])
        {
            return false;
        }

        // store the val of curr cell

        char val = grid[i][j];

        // mark the curr cell visited

        grid[i][j] = '#';

        // explore all the four directions

        for(int k = 0; k < 4; k++)
        {
            int new_i = i + dx[k];

            int new_j = j + dy[k];

            if(dfs(grid, new_i, new_j, n, m, word, pos + 1))
            {
                return true;
            }
        }

        // backtrack

        grid[i][j] = val;

        return false;
    }

    bool exist(vector<vector<char>>& grid, string word) {

        int n = grid.size();

        int m = grid[0].size();

        // call dfs for every cell

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dfs(grid, i, j, n, m, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};