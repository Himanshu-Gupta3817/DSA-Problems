/*Given a linked list containing 0’s, 1’s, 2’s, sort the linked list by doing a single traversal of it
Sample Input
12
0 1 2 2 1 0 0 2 0 1 1 0
Sample Output
0 0 0 0 0 1 1 1 1 2 2 2 */

#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void InsertAtEnd(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        head = tail = new node(data);
    }
    else
    {
        node *n = new node(data);
        tail->next = n;
        tail = n;
    }
}

node* SortLL(node*head){
	int zeroCount=0;
	int firstCount=0;
	int secondCount=0;

	node* temp=head;
	while(temp!=NULL){
		if(temp->data==0){
			zeroCount++;
		}
		else if(temp->data==1){
			firstCount++;
		}
		else if(temp->data==2){
			secondCount++;
		}
		temp=temp->next;
	}

	temp=head;
	while(temp!=NULL){
		if(zeroCount!=0){
			temp->data=0;
			zeroCount--;
		}
		else if(firstCount!=0){
			temp->data=1;
			firstCount--;
		}
		else if(secondCount!=0){
			temp->data=2;
			secondCount--;
		}
		temp=temp->next;
	}
	return head;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    //cout << "NULL\n";
}
int main () {
	node *head = NULL, *tail = NULL;
	int n,value;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>value;
		InsertAtEnd(head,tail,value);
	}
    SortLL(head);
	printLL(head);
	return 0;
}
