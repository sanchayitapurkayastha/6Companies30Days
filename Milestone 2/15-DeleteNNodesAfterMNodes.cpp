//Delete N nodes after skipping M nodes in Linked List

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        if (!head)  return;
        
        struct Node *p = head;
        
        while (p) {
            for (int i = 1; i < M && p; i ++)    p = p->next;
            if (!p) return;
            
            struct Node *q = p->next;
            for (int i = 1; i <= N && q; i ++) {
                struct Node *temp = q;
                q = q->next;
                free (temp);
            }
            
            p->next = q;
            p = q;
        }
        return;
    }
};
