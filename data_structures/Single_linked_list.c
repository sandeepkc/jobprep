#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
       {
             int key;
             struct node *next;
}; 

typedef struct node * nodeptr;

int list_length(nodeptr p)
{
    int len = 0;
    nodeptr temp = p;
    
    while(temp != NULL)
    {
                  ++len;
                  temp = temp->next;
                  }
    return (len);
}

nodeptr getnode()
{
        nodeptr temp = (nodeptr)malloc(sizeof(struct node));
        return (temp);
}

nodeptr insert_start(nodeptr head, int val)
{
        nodeptr temp;
        temp = (nodeptr)malloc(sizeof(struct node));
        temp->key = val;
        temp->next = head;
        head = temp;
        return (head);
}
                           
void insert_after(nodeptr p, int val)
{
        if(p == NULL)
             {
                     printf("insert_after: Void insertion.\n");
                     exit(1);
        }
                     
        nodeptr temp;
        temp = (nodeptr)malloc(sizeof(struct node));
        temp->key = val;
        temp->next = p->next;
        p->next = temp;
}

int delete_after(nodeptr p)
{
    if(p == NULL || p->next == NULL)
         {
         printf("delete_after: Void deletion.\n");
         exit(1);
    }
    
    nodeptr temp = p->next;
    int val = p->next->key;
    p->next = temp->next;
    free(temp);
    return (val);
}

nodeptr delete_head(nodeptr head, int *key)
{
        *key = head->key;
        nodeptr temp = head;
        head = head->next;
        free(temp);
        return (head);
}
            
int main(int argc, char **argv)
    {
             nodeptr head;
             head = (nodeptr)malloc(sizeof(struct node));
             head->key = 10;
             head->next = NULL;
             insert_after(head, 20);
             head = insert_start(head, 5);
             int val = delete_after(head);
             int val_head = 0;
             head = delete_head(head, &val_head);
             printf("Deleted key = %d.\n", val);
             printf("Deleted head key = %d.\n", val_head);
             printf("First = %d. \n", head->key);
             printf("Length of list is = %d.\n", list_length(head));
             //free(head->next);
             //free(head);             
             getch();
             return 0;
}
