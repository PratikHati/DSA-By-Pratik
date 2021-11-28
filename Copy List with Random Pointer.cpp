class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            Node *ans=new Node(head->val);
            ans->next=NULL;
            if(head->random==head)
                ans->random=ans;
            else
                ans->random=NULL;
            return ans;
        }
        
        Node *temp=head;
        int currdata=0;
        Node *Next=NULL;
        
        while(temp!=NULL){
            Next=temp->next;
            Node *newnode=new Node(temp->val);
            temp->next=newnode;
            newnode->next=Next;
            temp=Next;
        }
        
        temp=head;
        Next=temp->next;
        
        while(temp!=NULL){
            if(temp->random==NULL){
                Next->random=NULL;
            }
            else{
                Next->random=temp->random->next;
            }
            
            
            temp=temp->next->next;
            if(temp!=NULL)
                Next=temp->next;
        }
        
        Node *ans=head->next;
        Node *ANS=ans;
        temp=head;
        Node *middle=NULL;
        
        while(ans!=NULL){
            
            if(ans->next!=NULL){
                temp->next=ans->next;
                middle=ans->next;
                ans->next=ans->next->next;
                temp=middle;
                
            }
            else{
                temp->next=NULL;
                ans->next=NULL;
            }
            ans=ans->next;
            
        }
        
        return ANS;
        
    }
};