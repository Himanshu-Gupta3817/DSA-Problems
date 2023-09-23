/*
Given a binary tree , print its max path sum.
For this problem, a path is defined as any sequence of nodes from
some starting node to any node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.

Input Format
Single line input containing space separated integers denoting
the preorder input of the tree. NULL indicates that the node does not exist.

The tree looks like

                  8
               /
             3
           /     \
         4       10
       /    \       \
     1       9       5
   /         /
  2         7
The max path sum is given by : 7 + 9 + 4 + 3 + 10 + 5 = 38

Sample Input
8 3 4 1 2 NULL NULL NULL 9 7 NULL NULL NULL 10 NULL 5 NULL NULL NULL
Sample Output
38
*/

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){
    string s;
    cin >> s;
    if (s == "NULL") {
        return NULL;
    }

    int d = stoi(s);

    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


int ans = INT_MIN;
int maxPath(node *root) {
    if(root == NULL)
        return 0;
    int leftPath = max(0, maxPath(root->left));
    int rightPath = max(0, maxPath(root->right));

    ans = max(ans, root->data + leftPath + rightPath);

    return root->data + max(leftPath,rightPath);
}

int maxPathSum(node* root) {
    ans = INT_MIN;

    maxPath(root);

    return ans;
}


int main() {
    node *root = buildTree();

    int ans = maxPathSum(root);
    cout << ans << endl;
      return   0;
}
