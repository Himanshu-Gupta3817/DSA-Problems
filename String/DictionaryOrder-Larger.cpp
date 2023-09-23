/*
Take as input str, a string. Write a recursive function which
prints all the words possible by rearranging the characters of
this string which are in dictionary order larger than the given string.
The output strings must be lexicographically sorted.

Input Format
Single line input containing a string

Constraints
Length of string <= 10

All characters are unique

Output Format
Display all the words which are in dictionary order larger than the
string entered in a new line each. The output strings must be sorted.

Sample Input
cab

Sample Output
cba
Explanation
The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" .
Only one of them is lexicographically greater than "cab". We only print "cba".
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
			if(strcmp(inp,cm)>0){
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
