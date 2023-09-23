/*Find all the subsets of a given array that sum to k.

Input Format
The first line contains an integer N , the size of the array.
The next line conatins N integers. The next line contains an integer K.

Constraints
0 < N <= 20

Output Format
Output all the subsets that sum to K. The output should be printed as follows :

Sets with least no of elements should be printed first.
For equal length, elements that appear later in the original set,should be printed first.
Sample Input
5
1 4 6 5 3
10
Sample Output
6 4
3 6 1
5 4 1
Explanation
4 + 6 = 10
1 + 4 + 5 = 10
1 + 3 + 6 = 10
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ans;
void subsets(vector<int> ip, vector<int> &out, int i, int n)
{
    if (i == n)
    {
        ans.push_back(out);
        return;
    }
    subsets(ip, out, i + 1, n);
    out.push_back(ip[i]);
    subsets(ip, out, i + 1, n);
    out.pop_back();
}
int main()
{
    int n;
    cin >> n;
    int a;
    // vector<int> ip = {1, 4, 6, 5, 3};
    vector<int> ip;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        ip.push_back(a);
    }
    vector<int> out;
    int k;
	cin>>k;
    subsets(ip, out, 0, n);

    for (int i = 0; i < ans.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < ans[i].size(); j++)
        {
            // cout << ans[i][j] << " ";
            sum += ans[i][j];
        }
        // cout << "sum: " << sum << " ";
        if (sum == k)
        {
            for (int j = ans[i].size() - 1; j >= 0; j--)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
