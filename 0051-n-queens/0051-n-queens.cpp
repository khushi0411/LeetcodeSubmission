class Solution {
    
public:
    void solve(int col, vector<string>& board, vector<vector<string>> &ans, 
               vector<int>& leftrow, vector<int>&upperdiagonal, vector<int>&lowerdiagonal,
               int n
              ){
        //base case if col goes out of bound
        if(col == n){
            ans.push_back(board);
            return;
        }
        // triversing over the row
        for(int row = 0; row < n;row++){
            // if it is not visited in leftrow, upperdiagonal and lowerdiagonal then simply 
            // assign the queen
            if(leftrow[row] == 0 && upperdiagonal[row+col] == 0 &&
               lowerdiagonal[n-1+ col-row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiagonal[row+col] = 1;
                lowerdiagonal[n-1+col-row] = 1;
                // checking for another col
                solve(col+1, board,ans, leftrow, upperdiagonal, lowerdiagonal, n);
                // backtracking, removing it from the queue if recursion is done
                board[row][col] ='.';
                leftrow[row] = 0;
                upperdiagonal[row+col] = 0;
                lowerdiagonal[n-1+col-row] = 0;
            }
        }
    }
    
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // for storing the result
        vector<string> board(n);
        // for storing boards
        
        string s(n, '.');
        
        for(int i =0; i < n ;i++)
        {
            board[i] =s;
        }
        // making 3 vector to store the visiting record of the quuens if visisted then we can
        // simply say that this is not the correct place to place the queen
        vector<int>leftrow(n,0), upperdiagonal(2 * n - 1, 0) , lowerdiagonal(2* n- 1, 0);
        solve(0, board, ans, leftrow, upperdiagonal, lowerdiagonal,n);
        return ans;
        
    }
};