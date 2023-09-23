/*
Replace all occurrences of pi with 3.14

Input Format
Integer N, no of lines with one string per line

Constraints
0 < N < 1000
0 <= len(str) < 1000

Output Format
Output result one per line

Sample Input
3
xpix
xabpixx3.15x
xpipippixx
Sample Output
x3.14x
xab3.14xx3.15x
x3.143.14p3.14xx
Explanation
All occurrences of pi have been replaced with "3.14".
*/

#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int t;
	cout<<"Enter No. of lines: ";
	cin>>t;

	cout<<"\nEnter String: \n";
	while(t--){
		string s;
		cin>>s;

		int l=s.length();
		for(int i=0; i<l; i++){
			if(s[i]=='p' and s[i+1]=='i'){
				cout<<"3.14";
				i++;
			}
			else {
				cout<<s[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
