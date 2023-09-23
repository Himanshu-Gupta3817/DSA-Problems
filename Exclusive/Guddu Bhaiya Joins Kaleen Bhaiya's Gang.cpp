/*
Kaleen bhaiya is a big gangster in mirzapur and runs his own gang.
Guddu bhaiya wants to join Kaleen bhaiya's gang. K
aleen bhaiya has many enemies. So to defeat those enemies Kaleen bhaiya wants to recruit someone who is logically strong.
So if Guddu bhaiya wants to join the gang he has to pass a test.
In the test he will be given an enemy name, and he has to spoil that name by performing a special operation query.
The operation query involves moving the last letter to the place of the first letter and shifting all other letters one position ahead.
He has to perform the operation on part of the name which starts with index I and ends with index j.
He has to perform this operation query on the part k number of times.
He will be given n such operation queries.
And then he will give back the spoiled name to Kaleen bhaiya after performing all n operation queries.
You have to help Guddu bhaiya to do the task.

Input Format
First line will contain the enemy name in the form string name
Second line will contain an integer n denoting number of operation queries Guddu bhaiya has to perform.
Each of the next n lines will contain three integers i, j and k.

Constraints
Output Format
Print the spoiled name after performing all n operation queries.

Sample Input
dedfded
2
3 6 1
1 4 2
Sample Output
eddefdd
Explanation
For the name "dedfded",

After performing 1st operation query Guddu bhaiya will get "deedfdd".

After performing 2nd operation query he will get "eddefdd"
*/


#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
string reverseStr(string &s,int i,int j){
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;

    while(n--){
        int i,j,k;
        cin>>i>>j>>k;
        while(k--){
            s=reverseStr(s,i-1,j-1);
            s=reverseStr(s,i,j-1);
        }
    }
    cout<<endl;
    cout<<s;
}
