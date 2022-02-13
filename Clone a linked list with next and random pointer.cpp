Node *copyList(Node *head)
    {
        //Write your code here
        Node *temp1=head;
        
        Node *head2=new Node(-1);
        Node *temp2=head2;
        
        while(temp1!=NULL){
            
            int d=temp1->data;
            
            Node *n=new Node(d);
            
            temp2->next=n;
            temp2=temp2->next;
            
            temp1=temp1->next;    
        }
        
        temp1=head;
        temp2=head2->next;
        
        unordered_map<Node *,Node*>m;
        
        while(temp1!=NULL){
            
            m[temp1]=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        temp1=head;
        temp2=head2->next;
        
        while(temp1!=NULL){
            Node *help1=temp1->arb;
            Node *help2=m[help1];
            temp2->arb=help2;
            
            temp2=temp2->next;
            temp1=temp1->next;
        }
        
        return head2->next;
    }