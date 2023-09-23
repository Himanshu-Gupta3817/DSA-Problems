//Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

#include <iostream>
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
void reverseLL(node *&head, node *&tail)
{
    node *c = head;
    node *p = NULL;

    while (c != NULL)
    {
        node *n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    swap(head, tail);
}

void evenodd(node *&head)
{
	node *evenstart=NULL;
	node *evenend=NULL;
	node *oddend=NULL;
	node *oddstart=NULL;
	node *curr=head;
	while(curr!=NULL)
	{
		int val=curr->data;
		if(val %2==0)
		{
			if(evenstart==NULL)
			{
				evenstart=curr;
				evenend=evenstart;
			}
			else
			{
				evenend->next=curr;
				evenend=evenend->next;
			}
		}
		else{
			if(oddstart==NULL)
			{
				oddstart=curr;
				oddend=oddstart;
			}
			else
			{
				oddend->next=curr;
				oddend=oddend->next;
			}
		}
        curr=curr->next;
	}
	if(oddstart==NULL||evenstart==NULL)
	{

		return;
	}


	oddend->next=evenstart;
    evenend->next=NULL;
	head=oddstart;
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
int main() {
    node *head = NULL, *tail = NULL;
	int n,value;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>value;
		InsertAtEnd(head,tail,value);
	}

    evenodd(head);
    printLL(head);
    return 0;
}
