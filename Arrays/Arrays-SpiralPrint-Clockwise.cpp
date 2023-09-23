//Take as input a 2-d array. Print the 2-D array in sprial form clockwise.

#include <iostream>
using namespace std;

int main()
{

	int n,m;
	cin>>n>>m;

	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

	int sr, er, sc, ec;
    sr = sc = 0;
    er = n - 1;
    ec = m - 1;
    while (sr <= er and sc <= ec)
    {
        // 1.Print sr from sc to ec
        for (int col = sc; col <= ec; ++col)
        {
            cout << a[sr][col] << ", ";
        }
        sr++;

        //     // 2.Print ec from sr to er
        for (int row = sr; row <= er; ++row)
        {
            cout << a[row][ec] << ", ";
        }
        ec--;

        // 3.Print er from ec to sc
        if (sr <= er)
        {
            for (int col = ec; col >= sc; --col)
            {
                cout << a[er][col] << ", ";
            }
            er--;
        }

        // 4.Print sc from er to sr
        if (sc <= ec)
        {
            for (int row = er; row >= sr; --row)
            {
                cout << a[row][sc] << ", ";
            }
            sc++;
        }
    }
	cout<<"END";
    return 0;
}
