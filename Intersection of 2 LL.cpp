Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    map<int, bool> m;
    
    Node *temp1=head1;
    Node *temp2=head2;
    
    while(temp1!=NULL){
        m[temp1->data]=true;
        temp1=temp1->next;
    }
    
    Node *head=new Node(-1);
    Node *help=head;
    //Node *prev=NULL;
    
    map<int,bool> m_internal;
    
    while(temp2!=NULL){
        
        if(m[temp2->data]==true && m_internal[temp2->data]!=true){
            
            //DO OPERATION
            Node *n=new Node(temp2->data);
            help->next=n;
            help=n;
            m_internal[temp2->data]=true;
        }
        else{
            
            m[temp2->data]=true;
        }
        temp2=temp2->next;
    }
    
    return head->next; 
}