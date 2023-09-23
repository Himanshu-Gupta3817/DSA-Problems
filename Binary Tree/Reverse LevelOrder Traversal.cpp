/*
Given a binary tree, print it's nodes level by level in reverse order,
i.e., print all nodes present at the last level first, followed by nodes of the second last level and so on.
Print nodes at any level from left to right.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
The number of nodes in the tree is in the range [1, 1000]
0 <= root->data <= 1000

Output Format
Reverse level order print of the node values.

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
40 50 60 73 20 30 10
Explanation
Last level should be printed first, then second last , then third last and so on.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
vector<vector<int>> vec;
void lvlorder(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int> help;
        int n=q.size();
        for (int i = 0; i < n; i++)
        {
            node* temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            help.push_back(temp->data);

        }
        vec.push_back(help);
    }
    for (int i = vec.size()-1; i >=0 ; i--)
    {
          for (int j = 0; j < vec[i].size(); j++)
          {
               cout<<vec[i][j]<<" ";
          }
    }

}
int main()
{
    int n;
    cin>>n;
    node* p=new node(n);
    p->left=takeinp();
    p->right=takeinp();
    lvlorder(p);
 return 0;
}
