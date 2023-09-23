/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty.
The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M)
where it's cheese is waiting for. If a path exists-it is always unique.
Find that path and help the rat reach its cheese.

Input Format
First line contains 2 integers N and M denoting the rows and columns in the grid.
Next N line contains M characters each. An 'X' in position (i,j)
denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints
1 <= N , M <= 10

Output Format
Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell
is covered in the path and a 0 denotes that the cell is not covered in the path.
If a path does not exits then print "NO PATH FOUND"

Sample Input
5 4
OXOO
OOOX
XOXO
XOOX
XXOO
Sample Output
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 0
0 0 1 1
*/

#include <iostream>
using namespace std;

bool RatInAMaze(char maze[][100],int sol[][100],int i,int j,int n,int m){
    //1.Base Case
    if(i==n-1 and j==m-1){
        sol[i][j]=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
		cout<<endl;
        return true;
    }
    //2.Recurrsive Case
    sol[i][j]=1;
	//Right se raasta dekh kr aa
    if(j+1<m and maze[i][j+1]!='X' and sol[i][j+1]!=1){
        bool kyaRightSeRastaMilla = RatInAMaze(maze,sol,i,j+1,n,m);
        if(kyaRightSeRastaMilla==true){
            return true;
        }
    }
	//Neeche se rasta dekh kr aa
    if(i+1<n and maze[i+1][j]!='X' and sol[i+1][j]!=1){
        bool kyaNecheSeRastaMilla = RatInAMaze(maze,sol,i+1,j,n,m);
            if(kyaNecheSeRastaMilla==true){
                return true;
            }
        }
		//Left se rasta dekh kr aa
	if(j-1>=0 and maze[i][j-1]!='X' and sol[i][j-1]!=1){
		bool kyaLeftSeRastaMilla = RatInAMaze(maze,sol,i,j-1,n,m);
		if(kyaLeftSeRastaMilla==true){
			return true;
		}
	}
	//Uppar se rasta dekh kar aa
	if(i-1>=0 and maze[i-1][j]!='X' and sol[i-1][j]!=1){
		bool kyaUpparSeRastaMilla = RatInAMaze(maze,sol,i-1,j,n,m);
		if(kyaUpparSeRastaMilla==true){
			return true;
		}
	}
        sol[i][j]=0;
        return false;
}
int main() {

    //     char maze[][4]={
    //         "OXOO",
    //         "OOOX",
    //         "OOXO",
    //         "XOOO",
    //         "XXOO"
    // };
    int n,m;
    cin>>n>>m;
    char maze[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
        }
    }

    int sol[100][100]={0};

   bool ans= RatInAMaze(maze,sol,0,0,n,m);
   if(ans==false)
	cout<<"NO PATH FOUND";
  return 0;
}
