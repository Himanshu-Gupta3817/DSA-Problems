/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.


Input Format
First line contains a single integer N, denoting the number of bars in th histogram.
Next line contains N integers, ith of which, denotes the height of ith bar in the histogram.

Constraints
1<=N<=10^6
Height of each bar in histogram <= 10^10

Output Format
Output a single integer denoting the area of the required rectangle.

Sample Input
5
1 2 3 4 5
Sample Output
9
Explanation
The largest rectangle can be obtained of breadth=3 and length=3. Its starting index is 2 and ending index is 4 and it has a height of 3. Hence area = 3*3 = 9
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int largestRectangleArea(vector<int>& heights){
int n=heights.size();
vector<int> left(n),right(n);

stack<int> mystack;
for(int i=0;i<n;++i)  //Fill left
{
	if(mystack.empty())
	{   left[i]=0;  mystack.push(i);   }
		else
		{
			while(!mystack.empty() and heights[mystack.top()]>=heights[i])
			mystack.pop();
			left[i]=mystack.empty()?0:mystack.top()+1;
			mystack.push(i);
		}
}
	while(!mystack.empty())   //claer stack
	mystack.pop();

	for(int i=n-1;i>=0;--i)   //Fill right
	{
		if(mystack.empty())
		{  right[i]=n-1;  mystack.push(i); }
		else
		{
           while(!mystack.empty() and heights[mystack.top()]>=heights[i])
		   mystack.pop();
		   right[i]=mystack.empty()?n-1:mystack.top()-1;
		   mystack.push(i);
		}
	}
	int mxarea=0;
	for(int i=0;i<n;i++)
	mxarea=max(mxarea,heights[i]*(right[i]-left[i]+1));
	return mxarea;
}


int32_t main() {
	int n,numb;
	cin>>n;

	vector<int>heights;

	for(int i=0 ; i<n ; i++)
    {
        cin>>numb;
        heights.push_back(numb);
    }

	cout<<largestRectangleArea(heights);
	return 0;
}
