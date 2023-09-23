/*Given a binary tree and a number k, print out all root to leaf
 paths where the sum of all nodes value is same as the given number.

Input Format
First line contains the values of all the nodes in the binary tree in pre-order
format where true suggest the node exists and false suggests it is NULL.
Second line contains the number k.

Constraints
None

Output Format
Display the root to leaf path whose sum is equal to k.

Sample Input
10 true 20 true 30 false false true 50 false false true 40 true 60 false false true 73 false false
60
Sample Output
10 20 30
Explanation
The given tree is in pre order traversal. So convert it into binary tree and check root to leaf path sum.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* takeinp(){
    string inp;
    cin>>inp;
    if(inp=="true"){
        int n;
        cin>>n;
        node* p=new node(n);
        p->left=takeinp();
        p->right=takeinp();
        return p;
    }
    else{
        return NULL;
    }
}
vector<int> vec;
int k;
bool rtl(node* root,int sum){
    if(root==NULL){
        if(sum==k){
            return true;
        }
        return true;
    }
    vec.push_back(root->data);
    bool l=rtl(root->left,sum+root->data);
    if(l==true){
        return true;
    }
    vec.pop_back();
    vec.push_back(root->data);
    bool r=rtl(root->left,sum+root->data);
    if(r==true){
        return true;
    }
    vec.pop_back();
    return false;
}
int main()
{
    int n;
    cin>>n;
    node* p=new node(n);
    p->left=takeinp();
    p->right=takeinp();
    cin>>k;
    rtl(p,0);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }

    return 0;
}
