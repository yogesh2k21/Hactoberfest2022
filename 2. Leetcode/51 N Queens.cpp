#include <bits/stdc++.h>
using namespace std;
bool isValidStep(vector<vector<bool>> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col]) // if any other queen is present queen straight path then it return FALSE
            return false;
    }
    // we know we have note place queen below this call current so we will only check in upper part of the matrix
    // to understand this diagonal variable do a dry

    // checking in left upper diagonal
    int diagonalLeft = min(row, col);
    for (int i = 1; i <= diagonalLeft; i++)
    {
        if (board[row - i][col - i])
            return false;
    }

    // checking in right upper diagonal
    int diagonalRight = min(row, (int)(board.size() - col - 1));
    for (int i = 1; i <= diagonalRight; i++)
    {
        if (board[row - i][col + i])
            return false;
    }
    return true; // if any of the above condition will not true
}
void helper(vector<vector<bool>> &board, vector<vector<string>> &ans, int row)
{
    if (row == board.size())
    {
        // so we have to return 2D vector of string type vector in it
        vector<string> temp; // string vector which denote matrix in string form
        for (auto r : board)
        {
            string t = ""; // making string from row data
            for (auto cell : r)
            {
                if (cell == true) // if cell is true means there is Queen placed
                {
                    t += 'Q';
                }
                else // no queen blank area so we r putting '.' dot
                {
                    t += '.';
                }
            }
            temp.push_back(t); // pushing string in vector
        }
        ans.push_back(temp); // pushing vector inside 2d vector
        return;
    }

    for (int col = 0; col < board.size(); col++)
    {
        if (isValidStep(board, row, col))
        {
            board[row][col] = true; // Block this cell for future recursion calls
            helper(board, ans, row + 1);
            board[row][col] = false; // Block this cell for future recursion calls
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<vector<string>> ans;
    helper(board, ans, 0);
    return ans;
}
int main()
{
    vector<vector<string>> res = solveNQueens(4);
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << endl;
        cout << endl;
    }
    return 0;
}
