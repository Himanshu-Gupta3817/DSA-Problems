/*Take as input N, the size of array.
Take N more inputs and store that in an array.
Take as input “target”, a number.
Write a function which prints all pairs of numbers which sum to target.

Find any pair of elements in the array which has sum equal to target element and print them.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int isPair(int arr[], int n, int target){

    sort(arr,arr+n);

    int left=0,right=n-1;
    while(left<right){
        if(arr[left]+arr[right]==target){
            cout<<arr[left]<<" and "<<arr[right]<<endl;
            left++;
            right--;
        }
        else if(arr[left]+arr[right]>target){
            right--;
        }
        else{
            left++;
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<endl;

    int target;
    cin>>target;

   isPair(arr,n,target);

    return 0;
}
