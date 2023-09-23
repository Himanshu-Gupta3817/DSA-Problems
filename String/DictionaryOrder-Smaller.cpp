/*
Take as input str, a string. Write a recursive function which returns
all the words possible by rearranging the characters of this string
which are in dictionary order smaller than the given string.
The output strings must be lexicographically sorted.

Input Format
Single line input containing a string

Constraints
Length of string <= 10

All characters are unique

Output Format
Display all the words which are in dictionary order smaller
than the string entered in a new line each. The output strings must be sorted.

Sample Input
cab
Sample Output
abc
acb
bac
bca
Explanation
The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" .
Only four of them are lexicographically less than "cab". We print them in lexicographical order.
*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;

void Permutations(char* inp, int i,char* cm) {

	// base case
	if(inp[i] == '\0') {
		//cout << inp << endl;
			if(strcmp(inp,cm)<0){
				v.push_back(inp);
			}
		return;
	}

	// recursive case
	for(int j=i; j<strlen(inp); j++) {
		swap(inp[i], inp[j]);
		Permutations(inp, i+1,cm);
		swap(inp[i], inp[j]);
	}
}
int main() {
	char inp[10];
	cin>>inp;
	char cm[10];
	strcpy(cm,inp);
	Permutations(inp,0,cm);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}
