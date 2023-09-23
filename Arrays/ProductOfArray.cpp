#include<iostream>
using namespace std;
                        //product of array except self index
int main()
{
    int n,a[100];
    long long int pro=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                pro*=a[j];
            }
        }
        cout<<pro<<" ";
        pro=1;
    }
    return 0;
}
