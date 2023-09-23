/*
Take as input N, the size of array. Take N more inputs and
store that in an array. Take as input M, a number.
Write a recursive function which returns the first index at which M is
found in the array and -1 if M is not found anywhere. Print the value returned.

Input Format
Enter a number N and add N more elements to an array, then enter a number M

Constraints
None

Output Format
Display the first index at which number M is found

Sample Input
5
3
2
1
2
2
2
Sample Output
1
*/


#include<iostream>
using namespace std;

int FirstOcc(int arr[],int n,int i,int m){
	// 1.Base Case
	if(i==n){
		return -1;
	}
	//2. Recurrsive Case
	if(arr[i]==m){
		return i;
	}
	return FirstOcc(arr,n,i+1,m);
}


int main() {
	int n;
	cout<<"Enter No. of Array: ";
	cin>>n;

	cout<<"\nEnter Array:\n";
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int m;
	cout<<"\nEnter Number to be find: ";
	cin>>m;

	cout<<FirstOcc(arr,n,0,m);
	return 0;
}
