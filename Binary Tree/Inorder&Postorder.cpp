/*Given inorder and postorder traversal of a tree, construct the binary tree.Print the Preorder traversal of the tree formed.
All the values in the tree are unique.

Input Format
The first line contains an integer n - the number of nodes in the tree.
Next line contains n space separated integer equal to the inorder traversal.
Next line contains n space separated integer equal to the postorder traversal .

Constraints
1<=n<=10^4

Output Format
Print n space separated integer equal to the preorder traversal of the tree constructed.

Sample Input
4
4 1 3 2
4 3 2 1
Sample Output
1 4 2 3
Explanation
The output is the preorder traversal of the tree formed.
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void createMapping(int ino[],map<int,int> &nodeToIndex,int n){
    for(int i=0;i<n;i++){
    nodeToIndex[ino[i]]=i;
    }
}

Node* solve(int ino[], int post[], int &index, int inorderStart,int inorderEnd,int n, map<int,int> &nodeToIndex){
//base case
    if(index<0 || inorderStart > inorderEnd){
    return NULL;
    }

    int element=post[index--];
    Node* root=new Node(element);
    int position=nodeToIndex[element];
    root->right=solve(ino,post,index,position+1,inorderEnd,n,nodeToIndex);
    root->left=solve(ino,post,index,inorderStart,position-1,n,nodeToIndex);
    return root;
}


    Node *buildTree(int ino[], int post[], int n){
    int postorderIndex=n-1;
    map<int,int> nodeToIndex;
    createMapping(ino, nodeToIndex, n);
    Node* ans=solve(ino,post,postorderIndex,0,n-1,n,nodeToIndex);
    return ans;
    }

int main(){
    int n;
        cin>>n;
        int ino[n],post[n];
        for(int i=0;i<n;i++) cin>>ino[i];
        for(int i=0;i<n;i++) cin>>post[i];
        Node* root=buildTree(ino,post,n);
        preorder(root);
        cout<<endl;
return 0;
}
