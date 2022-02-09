/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(k==1){
        return head;
    }
    Node *curr=head->next;
    Node *prev=head;
    Node *nxt=curr;
    
    Node *last=head;
    
    int count=1;
    bool b=false;
    
    while(count<k && curr!=NULL){
        
        nxt=nxt->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        count++;
    }
    Node *temp=kReverse(nxt,k);
    last->next=temp;
    head=prev;
    return head;
}