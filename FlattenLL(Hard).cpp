Node *merge(Node *head1, Node *head2){
    
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    
    Node *head=new Node(-1);
    Node *temp=head;
    
    Node *temp1=head1;
    Node *temp2=head2;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data < temp2->data){
            temp->child=temp1;
            temp1=temp1->child;
            temp=temp->child;
            temp->next=NULL;
        }
        else{
           	temp->child=temp2;
            temp2=temp2->child;
            temp=temp->child;
            temp->child=NULL; 
        }
    }
    if(temp1!=NULL){
        temp->child=temp1;
    }
    if(temp2!=NULL){
        temp->child=temp2;
    }
    
    return head->child;
}

Node* flattenLinkedList(Node* head) 
{
    if(head==NULL){
        return head;
    }
	// Write your code here
    Node *temp=head;
    
    Node *nxt=temp->next;
    temp->next=flattenLinkedList(nxt);

    
    return merge(temp,temp->next);
}
