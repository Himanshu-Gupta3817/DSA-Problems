/*Take as input str, a string. We are concerned with all the possible
ascii-subsequences of str. E.g. “ab” has following ascii-subsequences
“”, “b”, “98”, “a”, “ab”, “a98”, “97”, “97b”, “9798”

a. Write a recursive function which returns the count of ascii-subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible ascii-subsequences for a given string (void is the return type for function).

Input Format
Enter the string

Constraints
None

Output Format
Display the number of ASCII-subsequences and display all the ASCII- subsequences

Sample Input
ab
Sample Output
 b 98 a ab a98 97 97b 9798
9
*/

#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
void reverse(int &x)
{
	int rem;
	int rev=0;
	while(x!=0){
		rem=x%10;
		rev=(rev*10)+rem;
		x=x/10;
	}
	x=rev;
}
void ascii_code(char in[],char out[],int i,int j){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<" ";
		return;
	}
	ascii_code(in,out,i+1,j);
	out[j]=in[i];
	ascii_code(in,out,i+1,j+1);
	int asci_code=in[i];
	reverse(asci_code);
	while(asci_code!=0){
		int rem=asci_code%10;
		out[j]=rem+'0';
		asci_code/=10;
		j++;
	}
	ascii_code(in,out,i+1,j);
}
int main() {
	char in[100];
	cin>>in;
	int size=strlen(in);
	char out[100];
	ascii_code(in,out,0,0);
	cout<<"\n";
	cout<<pow(3,size);

	return 0;
}
