/*
Given a circular array (the next element of the last element is the first element of the array),
print the Next Greater Number for every element. The Next Greater Number of a number x is the
first greater number to its traversing-order next in the array, which means you could search
circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Input Format
First line contains N - size of array.
Second line contains N space separated integers denoting array elements.

Constraints
2 <= Array.length <= 106

Output Format
Output the resultant array in a single line in space separated manner.

Sample Input
3
1 2 1
Sample Output
2 -1 2
Explanation
The first 1's next greater number is 2; The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.
*/


// WITHOUT TLE


#include <bits/stdc++.h>
using namespace std;

// Function to find the Next Greater Element(NGE)
void printNGE(int a[], int n)
{
    stack<int> s;
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && a[i % n] >= s.top())
            s.pop();
        if (i < n) {
            if (!s.empty())
                ans[i] = s.top();
            else
                ans[i] = -1;
        }
        s.push(a[i % n]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

/* Driver code */
int main() {

	int n;
	if(2<=n<=1000000)    cin>>n;

	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	printNGE(arr,n);

	return 0;
}
