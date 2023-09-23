/*There are two linked lists.
Due to some programming error, the end node of one of the linked list got linked into the second list, forming an inverted Y shaped list.
Now it's your job to find the point(Node) at which the two linked lists are intersecting.

Input Format
The first line of input is the size(N1) of the first linked list, followed by its content(Xi).
The third line of input is the size(N2) of the second linked list, followed by its content( Yi ).

Constraints
1<=N, N2<=100 0<=Xi, Yi<=100

Output Format
A single integer denoting the intersection point of two linked lists.
If the linked lists are not intersecting at any point then print -1.

Sample Input
5
10 20 30 40 50
4
15 25 40 50

Sample Output
40

Explanation
First and second linked list intersect at the node whose data value is 40.
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

int length(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        head = head->next;
        ans++;
    }
    return ans;
}


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


int intersection(node *&head1,node *&head2)
{
     int len1=length(head1);
     int len2=length(head2);
    int d=0;
    node *ptr1,*ptr2;
    if(len1>len2)
    {
        d=len1-len2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=len2-len1;
        ptr1=head2;
        ptr2=head1;
    }

	while(d!=0){
		ptr1=ptr1->next;
		d--;
	}
    while(ptr1!=NULL and ptr2!=NULL )
    {
        if (ptr1->data==ptr2->data){
        return ptr1->data;
		}
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
	return -1;
}

int main() {

	node*head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL;
    int n,value1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>value1;
		InsertAtEnd(head1,tail1,value1);
	}

	int m,value2;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>value2;
		InsertAtEnd(head2,tail2,value2);
	}

	cout<<intersection(head1,head2);
	return 0;
}
