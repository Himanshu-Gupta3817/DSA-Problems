/*You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Input Format
First line contains the numnber of nodes in list 1 Second line contains the N nodes of the first list.
Third line contains the number of nodes in the second list.
Fourth line contains the N2 number of nodes of the second list.

Constraints
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9

Output Format
Add the two numbers and return the sum as a linked list.

Sample Input
3
2 4 3
4
5 6 4 8
Sample Output
7 0 8
Explanation
342+465=708
*/

#include<iostream>
#include <list>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

// insert at tail
void insertAtTail(Node *&head, Node* &tail, int d)
{
    if (head == NULL){
        Node* n = new Node(d);
        head = tail = n;

    }else{
        Node* n = new Node(d);
        tail->next = n;
        tail = n;
    }
}

// void printLL(Node* head){
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }

// Node* Reverse(Node* head){
//     Node* prev=NULL;
//     Node* curr=head;
//     Node* forward = NULL;
//     while(curr!=NULL){
//         forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;
//     }
//     return prev;
// }

Node* solve(Node* li, Node* l2){
    //step-1: Reverse both LL
    // head1=Reverse(head1);
    // head2=Reverse(head2);
    Node* head1 = (li);
    Node* head2 = (l2);

    ///step-2: Add both LL
    //Node* ans=NULL;
    Node* newHead = NULL;
    Node* newTail = NULL;
    int carry=0;

        while(head1!= NULL && head2 != NULL ){
            insertAtTail(newHead,newTail,((head1->data + head2->data)+carry) % 10);
            carry = ((head1->data + head2->data)+carry) / 10;
            head1= head1-> next ;
            head2 = head2 -> next;

        }
        while(head1!= NULL){
            insertAtTail(newHead,newTail,((head1->data)+carry) % 10);
            carry = ((head1->data)+carry) / 10;
            head1= head1-> next;
        }
        while(head2 != NULL){
            insertAtTail(newHead,newTail,((head2->data)+carry) % 10);
            carry = (( head2->data)+carry) / 10;
            head2 = head2 -> next ;
        }
        if(carry != 0)
        {
            insertAtTail(newHead,newTail,(carry) % 10);
        }
    return newHead;
}


// for printing the LL
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){

    int n, no;
    cin >> n;
    Node*head1 = NULL;
    Node*tail1 = NULL;

    for (int i = 0; i < n; i++)
    {
        cin >> no;
        insertAtTail(head1,tail1,no);
    }

    cin>>n;
    Node*head2 = NULL;
    Node*tail2 = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        insertAtTail(head2,tail2,no);
    }

    head1 = solve(head1,head2);
    printLL(head1);
    //Reverse(ans);
    // printLL(head1);
    // printLL(head2);
return 0;
}
