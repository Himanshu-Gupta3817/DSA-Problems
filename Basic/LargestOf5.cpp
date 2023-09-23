#include<iostream>
#include<climits>
using namespace std;

int main () {

	int n,i,num,largest;
	i=1;
	n=5;
	largest = INT_MIN;

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
