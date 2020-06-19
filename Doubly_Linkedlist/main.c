#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};


int createlist(struct node *head)
{
    struct node *temp;
    int noofelements;
    printf("Enter the number of elements");
    scanf("%d",&noofelements);
    for (int i=1;i<=1;i++)
    {
        printf("Enter the data");
        scanf("%d",&head->data);
        head->previous=NULL;
        head->next=NULL;
        temp=head;

    }

    for(int i=2;i<=noofelements;i++)
    {
        struct node *n=(struct node *)malloc (sizeof(struct node));
        printf("Enter the data");
        scanf("%d",&n->data);
        n->next=NULL;
        n->previous=NULL;
        n->previous=temp;
        temp->next=n;
        temp=n;
    }

    //display(head);
}

int insertatmiddle(struct node *head)
{
    struct node *temp,*p;
    int pos;
    struct node *n=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&n->data);
    printf("Enter the position");
    scanf("%d",&pos);
    p=head;
    for(int i=1;i<pos;i++)
    {
      temp=p;
      p=p->next;
    }
    temp->next=n;
    n->previous=temp;
    n->next=p;
    p->previous=n;
    //display(head);
}

int insertatend(struct node *head)
{
    struct node *p=head;
    struct node *n=(struct node *) malloc (sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&n->data);
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=n;
    n->previous=p;
    n->next=NULL;
    //display(head);
}

int deleteatbeginning(struct node *head)
{
    struct node *temp;
    temp=head;
    head=head->next;
    head->previous=NULL;
    free(temp);
    //display(head);

}

int deleteatmiddle(struct node *head)
{
    struct node *p,*temp,*s;
    int pos;
    p=head;
    printf("Enter the position");
    scanf("%d",&pos);
    for (int i=1;i<pos;i++)
    {
        temp=p;
        p=p->next;
    }
    s=p->next;
    temp->next=s;
    s->previous=temp;
    p->next=NULL;
    p->previous=NULL;
    free(p);
   // display(head);


}

int deleteatend(struct node *head)
{

    struct node *p,*temp;
    p=temp=head;
    while (p->next!=NULL)
    {
        temp=p;
        p=p->next;
    }
    temp->next=NULL;
    p->previous=NULL;
    free(p);
    //display(head);
}

int display(struct node *head)
{
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
        printf("\n");
    }
}

int main()
{
    struct node *head;
    int choice;
    head=(struct node *)malloc (sizeof(struct node));
    while(1)
    {
        printf("Enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: createlist(head);
                    break;
            case 2: display(head);
                    break;
            case 3: insertatmiddle(head);
                    break;
            case 4: insertatend(head);
                    break;
            case 5:deleteatbeginning(head);
                    break;
            case 6:deleteatmiddle(head);
                   break;
            case 7: deleteatend(head);
                    break;
            default: printf("Invalid Input");
                     break;
        }
    }
    return 0;
}
