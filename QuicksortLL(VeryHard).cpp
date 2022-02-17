
struct node *gettail(struct node *root){
    
    node *temp=root;
    while(temp!=NULL && temp->next!=NULL){
        temp=temp->next;
    }
    
    return temp;
}

node * getpivot(struct node *head,struct node *tail,struct node **newhead,struct node **newtail){
    
    node *pivot=tail;
    node *curr=head;
    node *prev=NULL;
    node *last=pivot;
    
    while(curr!=pivot){
        if(curr->data < pivot->data){
            
            if(*newhead==NULL){
                *newhead=curr;
            }
            prev=curr;
            curr=curr->next;
        }
        else{
            if(prev){
                prev->next=curr->next;
            }
            node *help=curr->next;
            curr->next=NULL;
            last->next=curr;
            last=curr;
            curr=help;
        }
    }
    
    if(*newhead==NULL){
        *newhead=pivot;
    }
    
    *newtail=last;
    
    return pivot;
}

struct node *quicksort2(struct node *head,struct node *tail){
    
    if(head==tail || head==NULL){
        return head;    //single node or no node
    }
    
    node *newhead=NULL;
    node *newtail=NULL;
    
    node *pivot=getpivot(head,tail,&newhead,&newtail);
    
    if(newhead!=pivot){
        
        node *temp=newhead;
        while(temp->next!=pivot){
            temp=temp->next;
        }
        
        temp->next=NULL;
        newhead=quicksort2(newhead,temp);
        
        temp=gettail(newhead);
        temp->next=pivot;
    }
    
    pivot->next=quicksort2(pivot->next,newtail);
    
    return newhead;
}

void quickSort(struct node **headRef) {
    
   
    
    *headRef = quicksort2(*headRef,gettail(*headRef));
    
    return;
}