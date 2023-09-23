#include<iostream>
#include<climits>
using namespace std;

int main() {

	int n,i,largest,num;
	n=3;
	i=1;
	largest= INT_MIN;

	while(i<=n){
		cin>>num;
		if(num>largest){
			largest=num;
		}
		i+=1;
	}
	cout<<largest;

	return 0;
}
