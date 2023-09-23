/*
You are a cheater. You cheat in all exams and tests.
Now that mid sems of your first year in college are finally here,
you would like to cheat in these exams as well. You have the roll numbers of all the students in your class.
Now you want to know all the possible sitting arrangements of the students in your class.
Given an array arr of distinct integers, ie. the roll numbers of all the students of your class, print all the possible permutations.
Print all permutations in sorted order. Each line shows one possible permutation
Note: Please watch the Sample output once before submitting.

Input Format
First line takes an integer N (number of students in your class).
Second line contains N space separated integers (ie. the roll number of all students in your class).

Constraints
1<=N<=6
-10<=arr[i]<=10
All ar[i] must be unique

Output Format
Print all permutations in sorted order. Each line shows one possible permutation

Sample Input
3
3 2 1
Sample Output
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
Explanation
All possible permutation arrangement in sorted order is:
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> ans;
void Permutations(int *a, int n, int i)
{
    // Base Case
    if (i == n)
    {
        // for(int i = 0 ; i < n ; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        vector<int> v(a, a + n);
        ans.push_back(v);
        return;
    }
    // Recursive Case
    for (int j = i; j < n; j++)
    {
        swap(a[i], a[j]);
        Permutations(a, n, i + 1);
        swap(a[i], a[j]);
    }
}

int main()
{
    int a[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<endl;
    sort(a, a + n);
    Permutations(a, n, 0);

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
