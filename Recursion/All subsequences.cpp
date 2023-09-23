/*Print all the subsequences of a string in lexicographical order.

Input Format
First line contains an integer N, the no of strings.
Next, N lines follows one string per line.

Constraints
1 < len(str) < 20

Output Format
No of subsequences one per line

Sample Input
1
ab
Sample Output
a
ab
b

Explanation
4 subsequences are printed.
Empty string is a subsequence.
*/


#include<bits/stdc++.h>
using namespace std;
void subsequences(string s,string p,int i,vector<string>& v){
	//base case
	int n=s.size();
	if(i==n){
		v.push_back(p);
		return;
	}
	//ignore the ith
	subsequences(s,p+s[i],i+1,v);
	//consider the ith
	subsequences(s,p,i+1,v);
}
int main(){
	int n;
	cin>>n;

	while(n--){
		string s,p;
		cin>>s;

		vector<string>v;

		subsequences(s,p,0,v);
		sort(v.begin(),v.end());

		for(int i=0;i<v.size();i++){
			cout<<v[i]<<endl;
		}
	}
	return 0;
}
