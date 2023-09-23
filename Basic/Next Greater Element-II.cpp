/*
We are given a circular array, print the next greater number for every element.
If it is not found print -1 for that number.
To find the next greater number for element Ai , start from index i + 1
and go uptil the last index after which we start looking for the
greater number from the starting index of the array since array is circular.
*/

#include<iostream>
using namespace std;
int main() {
	int n;
    cin>>n;
	int arr[n];

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		int ans=-1;
		for(int j=i+1;j<2*n;++j){
			if(arr[i]<arr[j%n]){
				ans=arr[j%n];
				break;
			}
		}
			cout<<ans<<" ";
	}
	return 0;
}
