class Solution
{
    //Time Complexity O(N+N+N) O(N), N=number of nodes in list
    //Space Complexity O(1)
    public:
    Node* reverse(Node* head){
        Node *curr=head,*prev=NULL,*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
       Node* head2=reverse(head); //step 1
       Node* temp=head2;
       Node* prev;
       int carry=1;
       while(head2!=NULL){  //step 2 addition
           int sum=head2->data + carry;
           int unitD=sum%10;
           head2->data=unitD;
           carry=sum/10;
           if(carry==0) break;
           prev=head2;
           head2=head2->next;
       }
       if(carry>0) prev->next=new Node(carry);
       
       head=reverse(temp); //3rd step 
       return head;
    }
};
