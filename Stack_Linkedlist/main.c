#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *top)
{
  if (top==NULL)
    return 1;
  else
    return 0;

}

int push(struct node *top)
{
    int data;
    printf("Enter the data");
    scanf("%d",&data);
    struct node *n=(struct node *)malloc (sizeof(struct node));
    n->data=data;
    n->next=NULL;
    if(top==NULL)
    {
        top=n;
    }
    else{

           n->next=top;
            top=n;

    }
    return top;


}

int pop(struct node *top)
{
    int check;
    check=isEmpty(top);
    if(check==1)
        printf("The stack is Empty \n");
    else{

            struct node *p;
            p=top;
            top=p->next;
            free(p);
    }
    return top;

}

int peep (struct node *top)
{
     int check;
    check=isEmpty(top);
    if(check==1)
        printf("The stack is Empty \n");
    struct node *p;
    p=top;
    while(p!=NULL)
    {
        printf("The data present in the stack : %d",p->data);
         p=p->next;
         printf("\n");
    }
}


int main()
{
    int choice;
    struct node *top=NULL;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:top=push(top);
                   break;
            case 2:peep(top);
                   break;
            case 3:top=pop(top);
                   break;
            default:printf("Invalid Input");
                     break;
        }
    }

}
