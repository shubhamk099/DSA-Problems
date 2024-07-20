
#include<iostream>
using namespace std;

// structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
    public:

    // Function to check loop in the linked list.
    Node* CheckLoop(Node *head){
        Node *p,*q;
        p = head;
        q = head;
        while(p && q){
            p = p->next;
            q = q->next;
            q = (q!=NULL)?(q->next):NULL;
            if(p==q)
            return p;
        }
        return NULL;
    }
    
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *meet = CheckLoop(head);
        Node *first = head;
        
        if(meet!=NULL && meet!=head){   // Meeting not at head
            Node *prev = NULL;
            while(first!=meet){
                prev = meet;
                first = first->next;
                meet = meet->next;
            }
            prev->next = NULL;
        }
        
        if(meet!=NULL && meet==head){   // Meeting at head
            while(first->next!=head){
                first = first->next;
            }
            first->next = NULL;
        }
    }
};