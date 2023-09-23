/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 (3x3) sub-boxes of the grid.
*/

#include <iostream>
#include <cmath>
using namespace std;
bool isSafe(int board[][25], int i, int j, int no, int n)
{
    // row and column nhi hona chahiye no
    for (int k = 0; k < n; ++k)
    {
        if (board[i][k] == no || board[k][j] == no)
        {
            return false;
        }
    }

    // Lets iterate over the smaller box
    n = sqrt(n); // n=3
    int si = (i / n) * n;
    int sj = (j / n) * n;

    for (int k = si; k < si + n; ++k)
    {
        for (int l = sj; l < sj + n; ++l)
        {
            if (board[k][l] == no)
            {
                return false;
            }
        }
    }
    return true;
}
bool SudokoSolver(int board[25][25], int i, int j, int n)
{
    // 1.Base Case
    if (i == n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // 2.Recurrsive Case
    if (j == n)
    {
        return SudokoSolver(board, i + 1, 0, n);
    }
    if (board[i][j] != 0)
    {
        return SudokoSolver(board, i, j + 1, n);
    }

    // Ek empty cell ka kaam yaha kar rhey hai sabse pehle
    for (int no = 1; no <= n; no++)
    {
        if (isSafe(board, i, j, no, n))
        {
            board[i][j] = no;
            bool kyaBaakiSolveHua = SudokoSolver(board, i, j + 1, n);
            if (kyaBaakiSolveHua == true)
            {
                return true;
            }
            board[i][j] = 0; // backtracking
        }
    }
    return false;
}
int main()
{
	int n;
	cin>>n;
    // int mat[9][9] =
    //     {{5, 3, 0, 0, 7, 0, 0, 0, 0},
    //      {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //      {0, 9, 8, 0, 0, 0, 0, 6, 0},
    //      {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //      {4, 0, 0, 8, 0, 3, 0, 0, 1},
    //      {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //      {0, 6, 0, 0, 0, 0, 2, 8, 0},
    //      {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
	int board[25][25]={0};
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>board[i][j];
		}
	}
	cout<<endl;
    SudokoSolver(board, 0, 0, n);
    return 0;
}
