/*
Given a binary tree , Check if its mirror image is equal to the tree itself.

Input Format
The first line of the input contains level order traversal of the tree as space
separated integers . In the level order traversal , -1 represent a null child
while any other value represent a node of the tree.

Constraints
1<=number of nodes in the tree <=10^5

Output Format
Print "YES" without quotes if the mirror image of the tree is equal to the tree itself ,
else print "NO" without quotes.

Sample Input
1 2 2 -1 -1 -1 -1

Sample Output
YES

Explanation
The mirror image of given tree is equal to the tree itself.
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

Node* levelWiseBuild()
{
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    Node* root=new Node(data);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f=q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        if(l!=-1){
            f->left=new Node(l);
            q.push(f->left);
        }
        if(r!=-1){
            f->right=new Node(r);
            q.push(f->right);
        }
    }
    return root;
}


bool isMirror(Node *root1, Node *root2)
{
    // If both trees are empty, then they are mirror images
    if (root1 == NULL && root2 == NULL) return true;

    // For two trees to be mirror images,
    // 1.) Their root node's key must be same
    // 2.) left subtree of left tree and right subtree of
    // right tree have to be mirror images
    // 3.) right subtree of left tree and left subtree of
    // right tree have to be mirror images
    if (root1 && root2 && root1->data == root2->data){
        return isMirror(root1->left, root2->right)
               && isMirror(root1->right, root2->left);
    }
    return false;
}

bool isSymmetric(Node* root)
{
    // Check if tree is mirror of itself
    return isMirror(root, root);
}

int main()
{
    Node* root = levelWiseBuild();

    if (isSymmetric(root))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
