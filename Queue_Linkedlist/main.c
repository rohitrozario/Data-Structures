#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int display(struct node *front,struct node *rear)
{
  struct node *n;
     n=front;
    if(front==NULL)
    {
        printf("The Queue is Empty");
    }
    else{
            printf("The elements in the Queue: \n");
    while(n!=NULL)
    {
        printf("%d",n->data);
        printf("\n");
        n=n->next;
    }

    }
}

int main()
{
struct node *front=NULL,*rear=NULL,*p;



    while(1)
    {
         int choice;
        printf("Enter your choice 1) Enqueue 2) Display 3) Dequeue :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                 p=(struct node *)malloc(sizeof(struct node));
                 printf("Enter the data");
                 scanf("%d",&p->data);
                 p->next=NULL;
                 if(front==NULL)
                 {
                    front=p;
                    rear=p;
                  }
                 else{
                       rear->next=p;
                       rear=p;
                     }
               break;
        case 2:display(front,rear);
               break;
        case 3:
               if (front ==NULL)
                printf("The queue is Empty \n");
               else{
                p=front;
                if(front==rear)
                    front=rear=NULL;
                else{
                    front=front->next;
                    p->next=NULL;
                    free(p);
                }
               }
               break;
        default:printf(" Invalid Input ");
                break;
        }
    }

}
