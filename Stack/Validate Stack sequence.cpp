/*Given two sequences pushed and popped with distinct values,
return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

5
1 2 3 5 6
5 6 3 2 1
*/

#include<iostream>
#include<stack>
using namespace std;

bool VSS(int push[],int pop[], int len){
	int j=0;
	stack <int> s;
	for(int i=0;i<len;i++){
		s.push(push[i]);

		while(!s.empty() && j<len && s.top()==pop[j]){
			s.pop();
			j++;
		}
	}
	return j==len;
}
int main () {
	 int n;
    cin >> n;

    int push[n];

    for (int i = 0; i < n; i++)
    {
        cin >> push[i];
    }

	int pop[n];

    for (int i = 0; i < n; i++)
    {
        cin >> pop[i];
    }

	int len=sizeof(push)/sizeof(push[0]);

	cout << (VSS(push, pop, len) ? "true" : "false");
	return 0;
}
