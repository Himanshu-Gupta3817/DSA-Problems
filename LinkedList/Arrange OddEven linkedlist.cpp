/*We are Given a singly linked list, group all odd nodes together followed by the even nodes. Here we are talking about the node number and not the value in the nodes.
Note: i) You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
ii) The relative order inside both the even and odd groups should remain as it was in the input.
iii) The first node is considered odd, the second node even and so on

Original List: 1 2 3 4 5 6 7 8 9 10
Modified List: 1 3 5 7 9 2 4 6 8 10
*/

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

void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	// cout<<"NULL"<<endl;
}

void evenAfterOdd(node* &head){
	node* odd=head;
	node* even=head->next;
	node* evenStart=even;
	while(odd->next!=NULL && even->next!=NULL){
		odd->next=even->next;
		odd=odd->next;
		even->next=odd->next;
		even=even->next;
	}

	odd->next=evenStart;
	// if(odd->next==NULL){
	// 	even->next=NULL;
	// }
}
int main() {
	node* head=NULL,*tail=NULL;
	int n,value;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>value;
		InsertAtEnd(head,tail,value);
	}
	cout<<"Original List: ";
	display(head);
	cout<<endl;
	evenAfterOdd(head);
	cout<<"Modified List: ";
	display(head);
	return 0;
}
