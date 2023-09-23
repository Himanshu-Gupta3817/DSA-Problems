/*
You are given an empty chess board of size N*N.
Find the number of ways to place N queens on the board, s
uch that no two queens can kill each other in one move.
A queen can move vertically, horizontally and diagonally.

Input Format
A single integer N, denoting the size of chess board.

Constraints
1 ≤ N < 15

Output Format
A single integer denoting the count of solutions.

Sample Input
4
Sample Output
2
*/

#include <iostream>
using namespace std;

int count = 0;
bool isSafe(int board[][100], int i, int j, int n)
{
    int l = i, m = j;
    for (int k = 0; k < n; ++k)
    {
        if (board[k][j] == 1 || board[i][k] == 1)
        {
            return false;
        }
    }
    // Check upper right diagnol
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    // Check upper left diagnol
    while (l >= 0 and m >= 0)
    {
        if (board[l--][m--])
        {
            return false;
        }
    }
    return true;
}

bool NQueen(int board[][100], int i, int n)
{
    // 1.Base Case
    if (i == n)
    // {
    //     for (int i = 0; i < n; ++i)
    //     {
    //         for (int j = 0; j < n; ++j)
    //         {
    //             // cout << board[i][j] << " ";
    //             board[i][j] == 1 ? cout << "Q " : cout << "_ ";
    // if (board[i][j] == 1)
    {
        count++;
    }
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // return false;
    //}

    // 2.Recursive Case
    // Har column par jao ith row ke
    for (int j = 0; j < n; j++)
    {
        // check karo jis cell par ho waha queen rakhna safe hai ya nhi
        if (isSafe(board, i, j, n) == true)
        {
            board[i][j] = 1; // Agar safe hai to rakhdo

            // Ab baaki n-1 queens recursion ko pucho usne rakhi ya nhi ?
            bool kyaBaakiPlaceHui = NQueen(board, i + 1, n);
            // Agar place ho gayi to bas ban gayi baat
            if (kyaBaakiPlaceHui == true)
            {
                return true;
            }
            // Agar place nhi ho payi queens toh jo rakhi thi uski pos galat hai
            board[i][j] = 0; // backtracking
        }
    }
    return false; // Har column par check kar liya kahi nhi place huyi, ab return false
}
int main()
{
    int n;
    cin >> n;
    int board[100][100];

    NQueen(board, 0, n);
    cout << count;

    return 0;
}
