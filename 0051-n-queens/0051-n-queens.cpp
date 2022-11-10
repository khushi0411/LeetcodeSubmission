class Solution {
    
    public: 
    // checking if it is safe to put the queen at that place or not
    bool issafe(int row, int col, vector<string> board, int n){
        // check upper diagonal
        int duprow=  row;
        int dupcol =  col;
        
        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        // left side
     col=  dupcol;
        row= duprow;
        
        while(col >=0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        // lower diagonal
         row= duprow;
             col=  dupcol;
       
        while(row< n && col >=0)
        {

            if(board[row][col] == 'Q') return false;
            row++;
            col--;
            
        }
        return true;
    }
    
    public:
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n)
    {
        
        if(col == n) // base case 
            // if iterations reached at end point then the col will goes out of bound
        {
            ans.push_back(board);
            return;
        }
        // iteating over rows
        for(int row =  0; row < n; row++)
        {
            if(issafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }   
    }
    
public:  
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        // for storing the result
        vector<string> board(n);
        // for storing boards
        
        string s(n, '.');
        
        for(int i =0; i < n ;i++)
        {
            board[i] =s;
        }
        solve(0,board, ans, n); // solving
        return ans;
        
    }
};

