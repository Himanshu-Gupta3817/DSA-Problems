/*Given a binary tree, remove all the leaves from the tree

Input Format
Enter the value of the nodes of the tree

Constraints
None

Output Format
Display the tree in which all the leaves have been removed in pre-order traversal in the following format :
Left->data => Root->data <= Right->Data
Output END if left or right node is NULL

Sample Input
50 true 12 true 18 false false false false
Sample Output
12 => 50 <= END
END => 12 <= END
*/

#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

void buildTree(Node* &root) {
	string left, right;
	int d;
	cin >> d;
	root = new Node(d);
	cin >> left;
	if (left == "true") {
		buildTree(root->left);
	}
	cin >> right;
	if (right == "true") {
		buildTree(root->right);
	}
}

Node* removeLeaves(Node*root) {
	if (root == nullptr)
		return root;

	if (!root->left && !root->right) {
		delete root;
		return nullptr;
	}

	root->left = removeLeaves(root->left);
	root->right = removeLeaves(root->right);
	return root;
}


void PrintTree(Node*root) {
	if (root == nullptr)
		return;

	if (root->left)
		cout << root->left->data << " => ";
	else
		cout << "END => ";

	cout << root->data;

	if (root->right)
		cout << " <= " << root->right->data;
	else
		cout << " <= END";
	cout << endl;

	PrintTree(root->left);
	PrintTree(root->right);
}

int main() {
	Node* root = nullptr;
	buildTree(root);

	removeLeaves(root);

	PrintTree(root);

	return 0;
}
