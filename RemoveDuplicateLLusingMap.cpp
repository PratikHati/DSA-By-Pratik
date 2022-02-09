/****************************************************************
    Following is the class structure of the Node class:
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
#include<map>
Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    map<Node *,bool>m;
    
    m[head]=true;
    
    Node *temp=head->next;
    
    Node *prev=head;
 
    
    while(temp!=NULL){
        
        if(m[temp]==true){
    		if(temp->next==NULL){
                prev->next=NULL;
                temp=temp->next;
            }else{
                prev->next=temp->next;
                Node *toDel=temp;
                temp=temp->next;
                delete(toDel);
            }
        }
        else{
            m[temp]=true;
        	prev=temp;
        	temp=temp->next;
        }
    }
    
    return head;
}