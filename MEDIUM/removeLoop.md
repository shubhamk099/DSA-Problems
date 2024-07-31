## Remove loop in Linked List

Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list.  So if the next of the previous node is null. then there is no loop.  Remove the loop from the linked list, if it is present (we mainly need to make the next of the last node null). Otherwise, keep the linked list as it is.

Note: Given an integer, pos (1 based index)  Position of the node to which the last node links back if there is a loop. If the linked list does not have any loop, then pos = 0.

The generated output will be true if your submitted code is correct, otherwise, false.

Expected Time Complexity: O(n)

Expected Space Complexity: O(1)

Constraints:
1 ≤ size of linked list ≤ 105



```cpp
/*
structure of linked list node:
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
*/

// function to find meeting point of nodes
Node* meetingPoint(Node *head){
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
    
// function to remove a loop in the linked list.
void removeLoop(Node* head){
    Node *meet = CheckLoop(head);
    Node *first = head;
        
    if(meet!=NULL && meet!=head){   // meeting not at head
        Node *prev = NULL;
        while(first!=meet){
            prev = meet;
            first = first->next;
            meet = meet->next;
        }
        prev->next = NULL;
    }
        
    if(meet!=NULL && meet==head){   // meeting at head
        while(first->next!=head){
            first = first->next;
        }
        first->next = NULL;
    }
}
```