//avg time (for  successful search)= 1+(lamda/2)
//avg time (for  successful search)= 1+lamda
//where lamda(load factor)=no of keys/size of hash table
#include"iostream"
using namespace std;

struct Node         //hash table struct
{
    int data;       //store key value
    struct Node *next;//pointer to next node
};

//**h bcz pointer to array of Nodes
//circular LL with sorted order used here
void insert(struct Node **h,int k)//to create node and link it to hash table
{
    struct Node *t,*p=*h,*q=NULL;

    //create a new t node and allocate memory
    t=new Node;
    t->data=k;
    t->next=NULL;

    if(*h==NULL)//if no Node is present
        h=t;    //then link it
    else
    {
        while(p && p->data<k )//search until we found right place for "k"
        {
            q=p;        //store p in q
            p=p->next;  //move to next node
        }   
        // if(p!=NULL)     //if still nodes present after "t"
        // {
        //     t->next=q->next;//t->p
        //     q->next=t;//q->t
        // }
        // else            //if "t" is the last node
        // {
        //     q->next=t;//q->t
        //     t->next=NULL;//t->NULL
        // }
        // //DO LATER
    }
    
}

bool search(struct  Node *p,int k)//fuction to check whether key is hashed or not
{
    while(p)
    {
        if(p->data==k)
            return true;
        p=p->next;
    }
    return false;
}

int main()
{
    Node *HT[10];

    
    for(int i=0;i<10;i++)
    {
        HT[i]=NULL; //initialize with NULL
    }

    return 0;
}