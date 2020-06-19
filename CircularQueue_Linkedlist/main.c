#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


int main()
{
    int choice,data;
    struct node *front,*rear,*p;
    front=rear=NULL;
    while(1)
    {
        printf("Enter your choice 1)Enqueue 2)Display 3)Dequeue: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            p=(struct node *)malloc(sizeof(struct node));
            printf("Enter the data");
            scanf("%d",&p->data);
            p->next=NULL;
            if(front==NULL)
                front=rear=p;
            else
            {
                rear->next=p;
                rear=p;
            }
            rear->next=front;

        break;


        case 2:
                 p=front;
                if(front==NULL)
                 {
                          printf("The Queue is Empty \n");
                  }
                 else{
                        printf("The data present in the Queue \n");
                        do
                      {
                           printf("%d\n",p->data);
                         p=p->next;
                      }while(p!=front);
                     }
                    break;

        case 3:
            p=front;
            if (front==NULL)
                printf("The Queue is Empty \n");
            else{
                    if(front==rear)
                    {
                        front=rear=NULL;
                    }
                  else {
                front=front->next;
                rear->next=front;
                p->next=NULL;
                free(p);
            }
            }
            break;
        default: printf("Invalid Input");
        break;
        }

    }
}
